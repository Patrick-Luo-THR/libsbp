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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/orientation.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_orientation_MsgAngularRate) {
  static sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x222, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 34, 2, 66, 0, 17, 2, 0, 0, 0, 2,  0,  0,
        0,  5,  0, 0,  0, 2,  0, 0, 0, 0, 88, 70,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.angular_rate.flags = 0;

    test_msg.angular_rate.tow = 2;

    test_msg.angular_rate.x = 2;

    test_msg.angular_rate.y = 5;

    test_msg.angular_rate.z = 2;

    sbp_message_send(&sbp_state, SbpMsgAngularRate, 66, &test_msg,
                     &dummy_write);

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

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAngularRate, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.angular_rate.flags == 0,
                  "incorrect value for last_msg.msg.angular_rate.flags, "
                  "expected 0, is %d",
                  last_msg.msg.angular_rate.flags);

    ck_assert_msg(
        last_msg.msg.angular_rate.tow == 2,
        "incorrect value for last_msg.msg.angular_rate.tow, expected 2, is %d",
        last_msg.msg.angular_rate.tow);

    ck_assert_msg(
        last_msg.msg.angular_rate.x == 2,
        "incorrect value for last_msg.msg.angular_rate.x, expected 2, is %d",
        last_msg.msg.angular_rate.x);

    ck_assert_msg(
        last_msg.msg.angular_rate.y == 5,
        "incorrect value for last_msg.msg.angular_rate.y, expected 5, is %d",
        last_msg.msg.angular_rate.y);

    ck_assert_msg(
        last_msg.msg.angular_rate.z == 2,
        "incorrect value for last_msg.msg.angular_rate.z, expected 2, is %d",
        last_msg.msg.angular_rate.z);
  }
}
END_TEST

Suite *auto_check_sbp_orientation_MsgAngularRate_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_orientation_MsgAngularRate");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_orientation_MsgAngularRate");
  tcase_add_test(tc_acq, test_auto_check_sbp_orientation_MsgAngularRate);
  suite_add_tcase(s, tc_acq);
  return s;
}