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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <navigation.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static u32 n_callbacks_logged;
static u16 last_sender_id;
static u8 last_len;
static u8 last_msg[256];
static void *last_context;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  n_callbacks_logged = 0;
  last_context = 0;
  memset(last_msg, 0, sizeof(last_msg));
}

static void logging_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  n_callbacks_logged++;
  last_sender_id = sender_id;
  last_len = len;
  last_context = context;
  memcpy(last_msg, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

START_TEST(test_auto_check_sbp_navigation_23) {
  static sbp_msg_callbacks_node_t n;
  // static sbp_msg_callbacks_node_t n2;

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

    sbp_register_callback(&sbp_state, 0x212, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85, 18, 2,   66, 0, 42, 100, 0,   0,  0, 1,   0,   0,  0, 1,  0,   0,
        0,  1,  0,   0,  0, 0,  0,   128, 63, 0, 0,   128, 63, 0, 0,  128, 63,
        0,  0,  128, 63, 0, 0,  128, 63,  0,  0, 128, 63,  10, 0, 88, 205,
    };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x212, 66, sizeof(test_data), test_data,
                     &dummy_write);

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 66, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ned_cov_t *msg =
        (sbp_msg_vel_ned_cov_t *)((void *)last_msg + 6);
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((msg->cov_d_d * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_d_d, expected 1.0, is %f",
                  msg->cov_d_d);
    ck_assert_msg((msg->cov_e_d * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_e_d, expected 1.0, is %f",
                  msg->cov_e_d);
    ck_assert_msg((msg->cov_e_e * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_e_e, expected 1.0, is %f",
                  msg->cov_e_e);
    ck_assert_msg((msg->cov_n_d * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_n_d, expected 1.0, is %f",
                  msg->cov_n_d);
    ck_assert_msg((msg->cov_n_e * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_n_e, expected 1.0, is %f",
                  msg->cov_n_e);
    ck_assert_msg((msg->cov_n_n * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_n_n, expected 1.0, is %f",
                  msg->cov_n_n);
    ck_assert_msg(msg->e == 1, "incorrect value for e, expected 1, is %d",
                  msg->e);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n == 1, "incorrect value for n, expected 1, is %d",
                  msg->n);
    ck_assert_msg(msg->n_sats == 10,
                  "incorrect value for n_sats, expected 10, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 100,
                  "incorrect value for tow, expected 100, is %d", msg->tow);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_23_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_navigation_23");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_23");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_23);
  suite_add_tcase(s, tc_acq);
  return s;
}