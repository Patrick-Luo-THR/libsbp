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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_auto_check_sbp_navigation_19) {
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

    sbp_register_callback(&sbp_state, 0x20d, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  13,  2,   211, 136, 20, 40, 244, 122, 19, 248, 255, 255, 255,
        251, 255, 255, 255, 10,  0,  0,  0,   0,   0,  14,  0,   181, 99,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_vel_ecef_t *test_msg = (sbp_msg_vel_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 14;
    test_msg->tow = 326825000;
    test_msg->x = -8;
    test_msg->y = -5;
    test_msg->z = 10;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20d, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_data, sizeof(test_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 35027, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ecef_t *msg = (sbp_msg_vel_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 14,
                  "incorrect value for n_sats, expected 14, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326825000,
                  "incorrect value for tow, expected 326825000, is %d",
                  msg->tow);
    ck_assert_msg(msg->x == -8, "incorrect value for x, expected -8, is %d",
                  msg->x);
    ck_assert_msg(msg->y == -5, "incorrect value for y, expected -5, is %d",
                  msg->y);
    ck_assert_msg(msg->z == 10, "incorrect value for z, expected 10, is %d",
                  msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20d, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  13,  2,   211, 136, 20, 28, 246, 122, 19, 244, 255, 255, 255,
        238, 255, 255, 255, 11,  0,  0,  0,   0,   0,  15,  0,   215, 120,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_vel_ecef_t *test_msg = (sbp_msg_vel_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326825500;
    test_msg->x = -12;
    test_msg->y = -18;
    test_msg->z = 11;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20d, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_data, sizeof(test_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 35027, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ecef_t *msg = (sbp_msg_vel_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326825500,
                  "incorrect value for tow, expected 326825500, is %d",
                  msg->tow);
    ck_assert_msg(msg->x == -12, "incorrect value for x, expected -12, is %d",
                  msg->x);
    ck_assert_msg(msg->y == -18, "incorrect value for y, expected -18, is %d",
                  msg->y);
    ck_assert_msg(msg->z == 11, "incorrect value for z, expected 11, is %d",
                  msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20d, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  13,  2,   211, 136, 20, 16, 248, 122, 19, 248, 255, 255, 255,
        250, 255, 255, 255, 7,   0,  0,  0,   0,   0,  15,  0,   248, 221,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_vel_ecef_t *test_msg = (sbp_msg_vel_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->x = -8;
    test_msg->y = -6;
    test_msg->z = 7;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20d, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_data, sizeof(test_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 35027, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ecef_t *msg = (sbp_msg_vel_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  msg->tow);
    ck_assert_msg(msg->x == -8, "incorrect value for x, expected -8, is %d",
                  msg->x);
    ck_assert_msg(msg->y == -6, "incorrect value for y, expected -6, is %d",
                  msg->y);
    ck_assert_msg(msg->z == 7, "incorrect value for z, expected 7, is %d",
                  msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20d, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  13,  2,   211, 136, 20, 4, 250, 122, 19, 249, 255, 255, 255,
        239, 255, 255, 255, 16,  0,  0, 0,   0,   0,  15,  0,   1,   167,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_vel_ecef_t *test_msg = (sbp_msg_vel_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326826500;
    test_msg->x = -7;
    test_msg->y = -17;
    test_msg->z = 16;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20d, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_data, sizeof(test_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 35027, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ecef_t *msg = (sbp_msg_vel_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326826500,
                  "incorrect value for tow, expected 326826500, is %d",
                  msg->tow);
    ck_assert_msg(msg->x == -7, "incorrect value for x, expected -7, is %d",
                  msg->x);
    ck_assert_msg(msg->y == -17, "incorrect value for y, expected -17, is %d",
                  msg->y);
    ck_assert_msg(msg->z == 16, "incorrect value for z, expected 16, is %d",
                  msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20d, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  13,  2,   211, 136, 20, 248, 251, 122, 19, 247, 255, 255, 255,
        243, 255, 255, 255, 14,  0,  0,   0,   0,   0,  15,  0,   191, 43,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_vel_ecef_t *test_msg = (sbp_msg_vel_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->x = -9;
    test_msg->y = -13;
    test_msg->z = 14;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20d, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_data, sizeof(test_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(n_callbacks_logged == 1,
                  "one callback should have been logged");
    ck_assert_msg(last_sender_id == 35027, "sender_id decoded incorrectly");
    ck_assert_msg(last_len == sizeof(test_data), "len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg, test_data, sizeof(test_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    sbp_msg_vel_ecef_t *msg = (sbp_msg_vel_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  msg->tow);
    ck_assert_msg(msg->x == -9, "incorrect value for x, expected -9, is %d",
                  msg->x);
    ck_assert_msg(msg->y == -13, "incorrect value for y, expected -13, is %d",
                  msg->y);
    ck_assert_msg(msg->z == 14, "incorrect value for z, expected 14, is %d",
                  msg->z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_19_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_navigation_19");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_19");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_19);
  suite_add_tcase(s, tc_acq);
  return s;
}