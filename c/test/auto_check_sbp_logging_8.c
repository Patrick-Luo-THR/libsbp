/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <libsbp/sbp.h>
#include <libsbp/unpacked/logging.h>
#include <libsbp/logging.h>

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  sbp_msg_t msg;
  void *context;
} last_unpacked;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset()
{
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
  memset(&last_unpacked, 0, sizeof(last_unpacked));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[], u16 frame_len, u8 frame[], void *context)
{
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg, void *context)
{
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  last_unpacked.msg = *msg;
  last_unpacked.context = context;
}

START_TEST( test_auto_check_sbp_logging_8 )
{
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;
  static sbp_msg_callbacks_node_t n3;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x402, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x402, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x402, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 encoded_frame[] = {85,2,4,66,0,18,0,0,86,81,68,47,81,103,65,69,65,65,65,65,65,69,97,103,125,95, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    msg_fwd_t* test_msg = ( msg_fwd_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      memcpy(test_msg->fwd_payload, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->fwd_payload) == 0) {
        test_msg_len += sizeof(assign_string);
      }
      memcpy(test_unpacked_msg.MSG_FWD.fwd_payload, assign_string, sizeof(assign_string));
    }
    test_msg->protocol = 0;
    test_unpacked_msg.MSG_FWD.protocol = 0;
    test_msg->source = 0;
    test_unpacked_msg.MSG_FWD.source = 0;
    sbp_send_message(&sbp_state, 0x402, 66, test_msg_len, test_msg_storage, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
        "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 66,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 66,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x402,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_fwd_t* check_msg = ( msg_fwd_t *)((void *)last_msg.msg);
    sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      ck_assert_msg(memcmp(check_msg->fwd_payload, check_string, sizeof(check_string)) == 0, "incorrect value for check_msg->fwd_payload, expected string '%s', is '%s'", check_string, check_msg->fwd_payload);
      ck_assert_msg(memcmp(check_unpacked_msg->MSG_FWD.fwd_payload, check_string, sizeof(check_string)) == 0, "incorrect value for check_unpacked_msg->MSG_FWD.fwd_payload, expected string '%s', is '%s'", check_string, check_unpacked_msg->MSG_FWD.fwd_payload);
    }
    ck_assert_msg(check_msg->protocol == 0, "incorrect value for protocol, expected 0, is %d", check_msg->protocol);
    ck_assert_msg(check_unpacked_msg->MSG_FWD.protocol == 0, "incorrect value for check_unpacked_msg->MSG_FWD.protocol, expected 0, is %d", check_unpacked_msg->MSG_FWD.protocol);
    ck_assert_msg(check_msg->source == 0, "incorrect value for source, expected 0, is %d", check_msg->source);
    ck_assert_msg(check_unpacked_msg->MSG_FWD.source == 0, "incorrect value for check_unpacked_msg->MSG_FWD.source, expected 0, is %d", check_unpacked_msg->MSG_FWD.source);

    dummy_reset();
    logging_reset();

    sbp_pack_and_send_message(&sbp_state, 66, SBP_MSG_FWD, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
        "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 66,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 66,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x402,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    check_msg = ( msg_fwd_t *)((void *)last_msg.msg);
    check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      ck_assert_msg(memcmp(check_msg->fwd_payload, check_string, sizeof(check_string)) == 0, "incorrect value for check_msg->fwd_payload, expected string '%s', is '%s'", check_string, check_msg->fwd_payload);
      ck_assert_msg(memcmp(check_unpacked_msg->MSG_FWD.fwd_payload, check_string, sizeof(check_string)) == 0, "incorrect value for check_unpacked_msg->MSG_FWD.fwd_payload, expected string '%s', is '%s'", check_string, check_unpacked_msg->MSG_FWD.fwd_payload);
    }
    ck_assert_msg(check_msg->protocol == 0, "incorrect value for protocol, expected 0, is %d", check_msg->protocol);
    ck_assert_msg(check_unpacked_msg->MSG_FWD.protocol == 0, "incorrect value for check_unpacked_msg->MSG_FWD.protocol, expected 0, is %d", check_unpacked_msg->MSG_FWD.protocol);
    ck_assert_msg(check_msg->source == 0, "incorrect value for source, expected 0, is %d", check_msg->source);
    ck_assert_msg(check_unpacked_msg->MSG_FWD.source == 0, "incorrect value for check_unpacked_msg->MSG_FWD.source, expected 0, is %d", check_unpacked_msg->MSG_FWD.source);
  }
}
END_TEST

Suite* auto_check_sbp_logging_8_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_logging_8");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_logging_8");
  tcase_add_test(tc_acq, test_auto_check_sbp_logging_8);
  suite_add_tcase(s, tc_acq);
  return s;
}