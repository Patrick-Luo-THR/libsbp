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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by
// generate.py. Do not modify by hand!

#include <acquisition.h>
#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_payload;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 payload_len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
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
  memset(&last_payload, 0, sizeof(last_payload));
  memset(&last_frame, 0, sizeof(last_frame));
  memset(&last_unpacked, 0, sizeof(last_unpacked));
}

static void payload_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_payload.n_callbacks_logged++;
  last_payload.sender_id = sender_id;
  last_payload.len = len;
  last_payload.context = context;
  memcpy(last_payload.payload, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                           u8 payload[], u16 frame_len, u8 frame[],
                           void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.payload_len = payload_len;
  memcpy(last_frame.payload, payload, payload_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg,
                              void *context) {
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  memcpy(&last_unpacked.msg, msg, sizeof(*msg));
  last_unpacked.context = context;
}

START_TEST(test_auto_check_sbp_acquisition_2) {
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
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x1f, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x1f, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x1f, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  31, 0,  40, 12,  16, 72, 9, 34, 66, 155, 152,
        228, 67, 28, 34, 221, 68, 10, 0, 0,  0,  9,   189,
    };
    u8 test_encoded_payload_data[] = {
        72, 9, 34, 66, 155, 152, 228, 67, 28, 34, 221, 68, 10, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_c_t *test_msg =
        (sbp_msg_acq_result_dep_c_t *)&test_msg_storage;
    test_msg->cf = 1769.06591796875;
    test_msg->cn0 = 40.509063720703125;
    test_msg->cp = 457.1922302246094;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 10;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x1f, 3112, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_acq_result_dep_c_t *check_msg =
        (sbp_msg_acq_result_dep_c_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 1769.06591797 * 100) < 0.05,
                  "incorrect value for cf, expected 1769.06591797, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 40.5090637207 * 100) < 0.05,
                  "incorrect value for cn0, expected 40.5090637207, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 457.192230225 * 100) < 0.05,
                  "incorrect value for cp, expected 457.192230225, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 10,
                  "incorrect value for sid.sat, expected 10, is %d",
                  check_msg->sid.sat);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x1f, 3112,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 1769.06591797 * 100) < 0.05,
                  "incorrect value for cf, expected 1769.06591797, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 40.5090637207 * 100) < 0.05,
                  "incorrect value for cn0, expected 40.5090637207, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 457.192230225 * 100) < 0.05,
                  "incorrect value for cp, expected 457.192230225, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 10,
                  "incorrect value for sid.sat, expected 10, is %d",
                  check_msg->sid.sat);
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

    sbp_register_callback(&sbp_state, 0x1f, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x1f, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x1f, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 31, 0,  40,  12,  16,  132, 250, 45, 66, 207, 93,
        88, 68, 68, 185, 252, 195, 6,   0,   0,  0,  136, 185,
    };
    u8 test_encoded_payload_data[] = {
        132, 250, 45, 66, 207, 93, 88, 68, 68, 185, 252, 195, 6, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_c_t *test_msg =
        (sbp_msg_acq_result_dep_c_t *)&test_msg_storage;
    test_msg->cf = -505.4473876953125;
    test_msg->cn0 = 43.49464416503906;
    test_msg->cp = 865.4657592773438;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 6;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x1f, 3112, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_acq_result_dep_c_t *check_msg =
        (sbp_msg_acq_result_dep_c_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -505.447387695 * 100) < 0.05,
                  "incorrect value for cf, expected -505.447387695, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 43.494644165 * 100) < 0.05,
                  "incorrect value for cn0, expected 43.494644165, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 865.465759277 * 100) < 0.05,
                  "incorrect value for cp, expected 865.465759277, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 6,
                  "incorrect value for sid.sat, expected 6, is %d",
                  check_msg->sid.sat);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x1f, 3112,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -505.447387695 * 100) < 0.05,
                  "incorrect value for cf, expected -505.447387695, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 43.494644165 * 100) < 0.05,
                  "incorrect value for cn0, expected 43.494644165, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 865.465759277 * 100) < 0.05,
                  "incorrect value for cp, expected 865.465759277, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 6,
                  "incorrect value for sid.sat, expected 6, is %d",
                  check_msg->sid.sat);
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

    sbp_register_callback(&sbp_state, 0x1f, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x1f, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x1f, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  31, 0,   40,  12,  16,  163, 223, 24, 66, 64,  91,
        102, 67, 202, 243, 157, 196, 13,  0,   0,  0,  150, 161,
    };
    u8 test_encoded_payload_data[] = {
        163, 223, 24, 66, 64, 91, 102, 67, 202, 243, 157, 196, 13, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_c_t *test_msg =
        (sbp_msg_acq_result_dep_c_t *)&test_msg_storage;
    test_msg->cf = -1263.618408203125;
    test_msg->cn0 = 38.2183952331543;
    test_msg->cp = 230.3564453125;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 13;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x1f, 3112, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_acq_result_dep_c_t *check_msg =
        (sbp_msg_acq_result_dep_c_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -1263.6184082 * 100) < 0.05,
                  "incorrect value for cf, expected -1263.6184082, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 38.2183952332 * 100) < 0.05,
                  "incorrect value for cn0, expected 38.2183952332, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 230.356445312 * 100) < 0.05,
                  "incorrect value for cp, expected 230.356445312, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 13,
                  "incorrect value for sid.sat, expected 13, is %d",
                  check_msg->sid.sat);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x1f, 3112,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -1263.6184082 * 100) < 0.05,
                  "incorrect value for cf, expected -1263.6184082, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 38.2183952332 * 100) < 0.05,
                  "incorrect value for cn0, expected 38.2183952332, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 230.356445312 * 100) < 0.05,
                  "incorrect value for cp, expected 230.356445312, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 13,
                  "incorrect value for sid.sat, expected 13, is %d",
                  check_msg->sid.sat);
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

    sbp_register_callback(&sbp_state, 0x1f, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x1f, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x1f, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  31, 0,   40,  12, 16, 129, 65, 21, 66, 224, 214,
        124, 67, 243, 138, 61, 69, 1,   0,  0,  0,  109, 209,
    };
    u8 test_encoded_payload_data[] = {
        129, 65, 21, 66, 224, 214, 124, 67, 243, 138, 61, 69, 1, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_c_t *test_msg =
        (sbp_msg_acq_result_dep_c_t *)&test_msg_storage;
    test_msg->cf = 3032.684326171875;
    test_msg->cn0 = 37.313968658447266;
    test_msg->cp = 252.83935546875;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 1;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x1f, 3112, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_acq_result_dep_c_t *check_msg =
        (sbp_msg_acq_result_dep_c_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 3032.68432617 * 100) < 0.05,
                  "incorrect value for cf, expected 3032.68432617, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 37.3139686584 * 100) < 0.05,
                  "incorrect value for cn0, expected 37.3139686584, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 252.839355469 * 100) < 0.05,
                  "incorrect value for cp, expected 252.839355469, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 1,
                  "incorrect value for sid.sat, expected 1, is %d",
                  check_msg->sid.sat);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x1f, 3112,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 3032.68432617 * 100) < 0.05,
                  "incorrect value for cf, expected 3032.68432617, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 37.3139686584 * 100) < 0.05,
                  "incorrect value for cn0, expected 37.3139686584, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 252.839355469 * 100) < 0.05,
                  "incorrect value for cp, expected 252.839355469, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 1,
                  "incorrect value for sid.sat, expected 1, is %d",
                  check_msg->sid.sat);
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

    sbp_register_callback(&sbp_state, 0x1f, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x1f, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x1f, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  31, 0,   40,  12, 16, 126, 35, 62, 66, 226, 37,
        102, 68, 202, 243, 29, 69, 27,  0,  0,  0,  91,  67,
    };
    u8 test_encoded_payload_data[] = {
        126, 35, 62, 66, 226, 37, 102, 68, 202, 243, 29, 69, 27, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_c_t *test_msg =
        (sbp_msg_acq_result_dep_c_t *)&test_msg_storage;
    test_msg->cf = 2527.23681640625;
    test_msg->cn0 = 47.53466033935547;
    test_msg->cp = 920.5919189453125;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 27;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x1f, 3112, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_acq_result_dep_c_t *check_msg =
        (sbp_msg_acq_result_dep_c_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 2527.23681641 * 100) < 0.05,
                  "incorrect value for cf, expected 2527.23681641, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 47.5346603394 * 100) < 0.05,
                  "incorrect value for cn0, expected 47.5346603394, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 920.591918945 * 100) < 0.05,
                  "incorrect value for cp, expected 920.591918945, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 27,
                  "incorrect value for sid.sat, expected 27, is %d",
                  check_msg->sid.sat);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x1f, 3112,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 3112,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 2527.23681641 * 100) < 0.05,
                  "incorrect value for cf, expected 2527.23681641, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cn0 * 100 - 47.5346603394 * 100) < 0.05,
                  "incorrect value for cn0, expected 47.5346603394, is %f",
                  check_msg->cn0);
    ck_assert_msg((check_msg->cp * 100 - 920.591918945 * 100) < 0.05,
                  "incorrect value for cp, expected 920.591918945, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 27,
                  "incorrect value for sid.sat, expected 27, is %d",
                  check_msg->sid.sat);
  }
}
END_TEST

Suite *auto_check_sbp_acquisition_2_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_acquisition_2");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_acquisition_2");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_2);
  suite_add_tcase(s, tc_acq);
  return s;
}