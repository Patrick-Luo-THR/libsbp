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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py.
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

START_TEST(test_auto_check_sbp_navigation_12) {
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

    sbp_register_callback(&sbp_state, 0x209, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  9,   2,  211, 136, 32,  16, 248, 122, 19,  73, 29,  46, 132,
        182, 122, 68, 193, 219, 192, 29, 176, 121, 119, 80, 193, 83, 11,
        210, 90,  79, 75,  77,  65,  0,  0,   15,  2,   84, 6,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->x = -2684269.0326572997;
    test_msg->y = -4316646.751816;
    test_msg->z = 3839646.7095350414;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *msg = (sbp_msg_pos_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  msg->tow);
    ck_assert_msg((msg->x * 100 - -2684269.03266 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.03266, is %f",
                  msg->x);
    ck_assert_msg((msg->y * 100 - -4316646.75182 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.75182, is %f",
                  msg->y);
    ck_assert_msg((msg->z * 100 - 3839646.70954 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.70954, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  9,   2,  211, 136, 32,  248, 251, 122, 19,  103, 106, 57,  136,
        182, 122, 68, 193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
        97,  59,  79, 75,  77,  65,  0,   0,   15,  2,   147, 216,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->x = -2684269.064252186;
    test_msg->y = -4316646.762264892;
    test_msg->z = 3839646.463913912;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *msg = (sbp_msg_pos_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  msg->tow);
    ck_assert_msg((msg->x * 100 - -2684269.06425 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.06425, is %f",
                  msg->x);
    ck_assert_msg((msg->y * 100 - -4316646.76226 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.76226, is %f",
                  msg->y);
    ck_assert_msg((msg->z * 100 - 3839646.46391 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.46391, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  9,   2,  211, 136, 32,  224, 255, 122, 19,  101, 179, 242, 182,
        182, 122, 68, 193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
        253, 15,  79, 75,  77,  65,  0,   0,   15,  2,   40,  201,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326828000;
    test_msg->x = -2684269.4292816394;
    test_msg->y = -4316647.118271949;
    test_msg->z = 3839646.124909738;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *msg = (sbp_msg_pos_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326828000,
                  "incorrect value for tow, expected 326828000, is %d",
                  msg->tow);
    ck_assert_msg((msg->x * 100 - -2684269.42928 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.42928, is %f",
                  msg->x);
    ck_assert_msg((msg->y * 100 - -4316647.11827 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.11827, is %f",
                  msg->y);
    ck_assert_msg((msg->z * 100 - 3839646.12491 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.12491, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {
        85,  9,   2,  211, 136, 32, 200, 3,   123, 19,  146, 214, 132, 215,
        182, 122, 68, 193, 213, 68, 49,  215, 121, 119, 80,  193, 71,  34,
        110, 243, 78, 75,  77,  65, 0,   0,   15,  2,   187, 86,
    };
    sbp_msg_t test_msg_storage;
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326829000;
    test_msg->x = -2684269.683741399;
    test_msg->y = -4316647.3623821335;
    test_msg->z = 3839645.90179852;

    dummy_reset();
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *msg = (sbp_msg_pos_ecef_t *)&last_msg;
    // Run tests against fields
    ck_assert_msg(msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  msg->accuracy);
    ck_assert_msg(msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d", msg->flags);
    ck_assert_msg(msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  msg->n_sats);
    ck_assert_msg(msg->tow == 326829000,
                  "incorrect value for tow, expected 326829000, is %d",
                  msg->tow);
    ck_assert_msg((msg->x * 100 - -2684269.68374 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.68374, is %f",
                  msg->x);
    ck_assert_msg((msg->y * 100 - -4316647.36238 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.36238, is %f",
                  msg->y);
    ck_assert_msg((msg->z * 100 - 3839645.9018 * 100) < 0.05,
                  "incorrect value for z, expected 3839645.9018, is %f",
                  msg->z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_12_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_navigation_12");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_12");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_12);
  suite_add_tcase(s, tc_acq);
  return s;
}