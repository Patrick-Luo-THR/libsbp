//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgIarState.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_piksi_61() {
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 246, 215, 4, 1, 0, 0, 0, 216, 140]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 1,
                    "incorrect value for num_hyps, expected 1, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 0, 0, 0, 0, 18, 176]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 0,
                    "incorrect value for num_hyps, expected 0, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 1, 0, 0, 0, 166, 198]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 1,
                    "incorrect value for num_hyps, expected 1, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 217, 2, 0, 0, 6, 133]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 729,
                    "incorrect value for num_hyps, expected 729, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 216, 2, 0, 0, 178, 243]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 728,
                    "incorrect value for num_hyps, expected 728, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 215, 2, 0, 0, 92, 39]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 727,
                    "incorrect value for num_hyps, expected 727, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 25, 0, 195, 4, 4, 211, 2, 0, 0, 173, 237]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgIarState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x19,
                    "Incorrect message type, expected 0x19, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.num_hyps, 723,
                    "incorrect value for num_hyps, expected 723, is {}",
                    msg.num_hyps
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIarState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
