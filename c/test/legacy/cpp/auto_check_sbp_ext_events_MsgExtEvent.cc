/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_handler.h>
#include <libsbp/legacy/cpp/message_traits.h>
class Test_legacy_auto_check_sbp_ext_events_MsgExtEvent0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ext_event_t> {
 public:
  Test_legacy_auto_check_sbp_ext_events_MsgExtEvent0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ext_event_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ext_event_t *>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_ext_event_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ext_event_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ext_events_MsgExtEvent0, Test) {
  uint8_t encoded_frame[] = {
      85, 1,  1,   245, 6,  12, 48, 7, 199, 216,
      49, 15, 202, 65,  15, 0,  3,  0, 62,  204,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ext_event_t *test_msg = (msg_ext_event_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 3;
  test_msg->ns_residual = 999882;
  test_msg->pin = 0;
  test_msg->tow = 254924999;
  test_msg->wn = 1840;

  EXPECT_EQ(send_message(0x101, 1781, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1781);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 3)
      << "incorrect value for flags, expected 3, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 999882)
      << "incorrect value for ns_residual, expected 999882, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->pin, 0)
      << "incorrect value for pin, expected 0, is " << last_msg_->pin;
  EXPECT_EQ(last_msg_->tow, 254924999)
      << "incorrect value for tow, expected 254924999, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1840)
      << "incorrect value for wn, expected 1840, is " << last_msg_->wn;
}