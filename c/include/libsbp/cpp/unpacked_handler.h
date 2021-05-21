/**
 * Copyright (C) 2019 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_UNPACKED_MESSAGE_HANDLER_H_
#define SBP_CPP_UNPACKED_MESSAGE_HANDLER_H_

#include <cassert>
#include <array>

#include <libsbp/cpp/state.h>
#include <libsbp/cpp/unpacked_message_traits.h>

namespace sbp {

/**
 * A convenience type alias for class member functions that accept SBP message callbacks
 */
template<typename ClassT, typename ArgT>
using CallbackUnpackedFn = void (ClassT::*)(uint16_t, const ArgT &);

/**
 * A helper function for calling a C++ object member function from a libsbp callback.
 *
 * This function is registered with libsbp as a callback and calls a specific member function
 * of an object from that callback with the SBP message decoded. The member function pointer
 * is encoded into the template parameter, and the instance of the object is passed in via
 * the `context` parameter.
 *
 * @tparam MsgT The message type to decode the payload as
 * @tparam ClassT The class type to call the function on
 * @tparam func Pointer to the member function to call
 *
 * @param sender_id The decoded sender ID, is forwarded on to `func`
 * @param len The length of the message, is forwarded on to `func`
 * @param msg The raw message payload
 * @param context Pointer to an instance of `ClassT` to call `func` on
 */
template<typename MsgT, typename ClassT, CallbackUnpackedFn<ClassT, MsgT> func>
inline void sbp_unpacked_cb_passthrough(uint16_t sender_id, uint16_t msg_type, const sbp_msg_t *msg, void *context) {
  (void)msg_type;
  assert(nullptr != context);
  assert(msg_type == sbp::MessageTraits<MsgT>::id);

  auto instance = static_cast<ClassT *>(context);
  auto val = sbp::MessageTraits<MsgT>::get(*msg);
  ((*instance).*(func))(sender_id, val);
}

namespace details {

/**
 * Recursive interface type for defining the interface functions for `UnpackedMessageHandler`.
 *
 * These types define a virtual `handle_sbp_msg()` for handling a specific SBP message type,
 * as well as a function for registering it as a SBP callback.
 *
 * @note These types aren't meant to be used directly by application code.
 *
 * @tparam MsgType The type of SBP message to define an interface for
 * @tparam OtherTypes Other types to recursively define interfaces for
 */
template<typename MsgType, typename... OtherTypes>
class UnpackedInterface : UnpackedInterface<OtherTypes...> {
 public:
  UnpackedInterface() = default;
  ~UnpackedInterface() override = default;

  using UnpackedInterface<OtherTypes...>::handle_sbp_msg;
  virtual void handle_sbp_msg(uint16_t sender_id, const MsgType& msg) = 0;

 protected:
  void register_callback(sbp_state_t *state, sbp_msg_callbacks_node_t nodes[]) {
    sbp_register_unpacked_callback(state,
        sbp::MessageTraits<MsgType>::id,
        &sbp_unpacked_cb_passthrough<MsgType, UnpackedInterface, &UnpackedInterface::handle_sbp_msg>,
        this,
        &nodes[0]);
    UnpackedInterface<OtherTypes...>::register_callback(state, &nodes[1]);
  }
};

template<typename MsgType>
class UnpackedInterface<MsgType> {
 public:
  UnpackedInterface() = default;
  virtual ~UnpackedInterface() = default;

  virtual void handle_sbp_msg(uint16_t sender_id, const MsgType& msg) = 0;
 protected:
  void register_callback(sbp_state_t *state, sbp_msg_callbacks_node_t nodes[]) {
    sbp_register_unpacked_callback(state,
                          sbp::MessageTraits<MsgType>::id,
                          &sbp_unpacked_cb_passthrough<MsgType, UnpackedInterface, &UnpackedInterface::handle_sbp_msg>,
                          this,
                          &nodes[0]);
  }
};

} // namespace details

/**
 * Base type for defining classes that handle SBP messages
 *
 * Application classes should derive from this class if they wish to handle
 * SBP messages with a member function. `UnpackedMessageHandler` instantiates all of
 * the callback nodes, and registers the member functions with the given
 * `sbp_state_t`.
 *
 * Classes that derive from `UnpackedMessageHandler` need to implement
 *   void handle_sbp_msg(uint16_t sender_id, const MsgType& msg);
 * for each `MsgType` in the list of message types given as template parameters.
 *
 * Due to the nature of the callback registration in libsbp we dissallow copying or
 * moving of `UnpackedMessageHandler`.
 *
 * @note It should not matter if the class derives publicly or privately from `UnpackedMessageHandler`
 * or if the `handle_sbp_msg` functions are public or private.
 *
 * @example
 * class ECEFHandler : private sbp::UnpackedMessageHandler<sbp_msg_gps_time_t, sbp_msg_pos_ecef_t> {
 *   public:
 *     ECEFHandler(sbp::State *state) : sbp::UnpackedMessageHandler<sbp_msg_gps_time_t, sbp_msg_pos_ecef_t>(state) {
 *       // The callbacks have already been registered
 *       // Perform other initialization tasks
 *     }
 *
 *     void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_t& msg) {
 *       // handle GPS time message
 *     }
 *
 *     void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_t& msg) {
 *       // handle pos ECEF message
 *     }
 * };
 *
 * @tparam MsgTypes List of SBP message types to register callbacks for
 */
template<typename... MsgTypes>
 class UnpackedMessageHandler : public details::UnpackedInterface<MsgTypes...> {
    static constexpr size_t kMsgCount = sizeof...(MsgTypes);

    State &state_;
    std::array<sbp_msg_callbacks_node_t, kMsgCount> callback_nodes_;

  public:

    explicit UnpackedMessageHandler(State *state) : details::UnpackedInterface<MsgTypes...>(), state_(*state), callback_nodes_() {
      details::UnpackedInterface<MsgTypes...>::register_callback(state_.get_state(), callback_nodes_.data());
    }

    ~UnpackedMessageHandler() override {
        for (auto& node : callback_nodes_) {
            sbp_remove_callback(state_.get_state(), &node);
        }
    }

    UnpackedMessageHandler(const UnpackedMessageHandler&) = delete;
    UnpackedMessageHandler(UnpackedMessageHandler&& other) = delete;
    UnpackedMessageHandler& operator=(const UnpackedMessageHandler&) = delete;
    UnpackedMessageHandler& operator=(UnpackedMessageHandler&&) = delete;

    using details::UnpackedInterface<MsgTypes...>::handle_sbp_msg;
};

template<typename ClassT>
using CallbackSbpMsgFn = void (*ClassT::*)(uint16_t, uint16_t, const sbp_msg_t &);

template<typename ClassT>
inline void sbp_all_unpacked_cb_passthrough(uint16_t sender_id, uint16_t msg_type,
                                     const sbp_msg_t *msg,
                                     void *context) {
  assert(nullptr != context);

  auto *instance = static_cast<ClassT *>(context);
  instance->handle_sbp_message(sender_id, msg_type, *msg);
}

class AllUnpackedHandler {
    State &state_;
    sbp_msg_callbacks_node_t callback_node_;

  public:

    explicit AllUnpackedHandler(State *state) : state_(*state), callback_node_() {
      sbp_register_all_unpacked_callback(state_.get_state(),
              sbp_all_unpacked_cb_passthrough<AllUnpackedHandler>,
              this,
              &callback_node_);
    }

    virtual ~AllUnpackedHandler() {
        sbp_remove_callback(state_.get_state(), &callback_node_);
    }

    AllUnpackedHandler(const AllUnpackedHandler&) = delete;
    AllUnpackedHandler(AllUnpackedHandler&& other) = delete;
    AllUnpackedHandler& operator=(const AllUnpackedHandler&) = delete;
    AllUnpackedHandler& operator=(AllUnpackedHandler&&) = delete;
    
    virtual void handle_sbp_message(uint16_t sender_id, uint16_t msg_type, const sbp_msg_t &msg) = 0;
};

} /* namespace sbp */

#endif /* SBP_CPP_MESSAGE_HANDLER_H_ */
