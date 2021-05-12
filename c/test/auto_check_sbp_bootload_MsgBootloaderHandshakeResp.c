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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <libsbp/sbp.h>
#include <libsbp/unpacked/bootload.h>
#include <libsbp/packed/bootload.h>

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

START_TEST( test_packed_auto_check_sbp_bootload_MsgBootloaderHandshakeResp )
{
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

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

    sbp_register_callback(&sbp_state, 0xb4, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xb4, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,180,0,0,0,9,0,0,0,0,118,49,46,50,10,201,1, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_bootloader_handshake_resp_t* test_msg = ( msg_bootloader_handshake_resp_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->flags = 0;
    {
      const char assign_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      memcpy(test_msg->version, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->version) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xb4, 0, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 0,
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
    ck_assert_msg(last_frame.sender_id == 0,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xb4,
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
    msg_bootloader_handshake_resp_t* check_msg = ( msg_bootloader_handshake_resp_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    {
      const char check_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      ck_assert_msg(memcmp(check_msg->version, check_string, sizeof(check_string)) == 0, "incorrect value for check_msg->version, expected string '%s', is '%s'", check_string, check_msg->version);
    }
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xb0, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xb0, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,176,0,195,4,4,118,49,46,50,1,206, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_bootloader_handshake_dep_a_t* test_msg = ( msg_bootloader_handshake_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->handshake) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->handshake[0]);
    }
    
    test_msg->handshake[0] = 118;
    if (sizeof(test_msg->handshake) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->handshake[0]);
    }
    
    test_msg->handshake[1] = 49;
    if (sizeof(test_msg->handshake) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->handshake[0]);
    }
    
    test_msg->handshake[2] = 46;
    if (sizeof(test_msg->handshake) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->handshake[0]);
    }
    
    test_msg->handshake[3] = 50;
    sbp_send_message(&sbp_state, 0xb0, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xb0,
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
  }
}
END_TEST

START_TEST( test_unpacked_auto_check_sbp_bootload_MsgBootloaderHandshakeResp )
{
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
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0xb4, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,180,0,0,0,9,0,0,0,0,118,49,46,50,10,201,1, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_RESP.flags = 0;
    
    {
      const char assign_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      memcpy(test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_RESP.version.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_RESP.version.len = 5;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BOOTLOADER_HANDSHAKE_RESP, 0, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 0,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_bootloader_handshake_resp_t* check_msg = ( msg_bootloader_handshake_resp_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.flags == 0, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.flags, expected 0, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.flags);
    
    {
      const char check_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      ck_assert_msg(memcmp(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.data, check_string, sizeof(check_string)) == 0, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.data, expected string '%s', is '%s'", check_string, check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.data);
    }
    
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.len == 5, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.len, expected 5, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_RESP.version.len);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0xb0, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,176,0,195,4,4,118,49,46,50,1,206, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[0] = 118;
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[1] = 49;
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[2] = 46;
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[3] = 50;
    
    test_unpacked_msg.MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.len = 4;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A, 1219, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 1219,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_bootloader_handshake_dep_a_t* check_msg = ( msg_bootloader_handshake_dep_a_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[0] == 118, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[0], expected 118, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[0]);
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[1] == 49, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[1], expected 49, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[1]);
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[2] == 46, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[2], expected 46, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[2]);
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[3] == 50, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[3], expected 50, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.data[3]);
    
    ck_assert_msg(check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.len == 4, "incorrect value for check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.len, expected 4, is %d", check_unpacked_msg->MSG_BOOTLOADER_HANDSHAKE_DEP_A.handshake.len);
  }
}
END_TEST

Suite* auto_check_sbp_bootload_MsgBootloaderHandshakeResp_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_bootload_MsgBootloaderHandshakeResp");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_bootload_MsgBootloaderHandshakeResp");
  tcase_add_test(tc_acq, test_packed_auto_check_sbp_bootload_MsgBootloaderHandshakeResp);
  tcase_add_test(tc_acq, test_unpacked_auto_check_sbp_bootload_MsgBootloaderHandshakeResp);
  suite_add_tcase(s, tc_acq);
  return s;
}