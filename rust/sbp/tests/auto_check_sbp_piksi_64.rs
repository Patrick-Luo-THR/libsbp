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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_piksi_64() {
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 246, 215, 26, 109, 97, 105, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 156, 9, 0, 0, 73, 138,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 0,
                    "incorrect value for cpu, expected 0, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "main                ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "main                ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 2460,
                    "incorrect value for stack_free, expected 2460, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 246, 215, 26, 105, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 83, 2, 36, 0, 0, 0, 151, 20,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 595,
                    "incorrect value for cpu, expected 595, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "idle                ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "idle                ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 36,
                    "incorrect value for stack_free, expected 36, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 246, 215, 26, 78, 65, 80, 32, 73, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 14, 0, 116, 4, 0, 0, 226, 60,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 14,
                    "incorrect value for cpu, expected 14, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "NAP ISR             ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "NAP ISR             ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 1140,
                    "incorrect value for stack_free, expected 1140, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 246, 215, 26, 83, 66, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 196, 19, 0, 0, 90, 169,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 1,
                    "incorrect value for cpu, expected 1, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "SBP                 ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "SBP                 ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 5060,
                    "incorrect value for stack_free, expected 5060, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 246, 215, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 7, 0, 20, 9, 0, 0, 47, 75,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 7,
                    "incorrect value for cpu, expected 7, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "manage acq          ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "manage acq          ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 2324,
                    "incorrect value for stack_free, expected 2324, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 109, 97, 105, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 148, 9, 0, 0, 195, 212,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 0,
                    "incorrect value for cpu, expected 0, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "main                ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "main                ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 2452,
                    "incorrect value for stack_free, expected 2452, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 105, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 228, 1, 36, 0, 0, 0, 225, 18,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 484,
                    "incorrect value for cpu, expected 484, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "idle                ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "idle                ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 36,
                    "incorrect value for stack_free, expected 36, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 78, 65, 80, 32, 73, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 138, 1, 92, 7, 0, 0, 166, 116,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 394,
                    "incorrect value for cpu, expected 394, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "NAP ISR             ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "NAP ISR             ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 1884,
                    "incorrect value for stack_free, expected 1884, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 83, 66, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 4, 12, 0, 0, 229, 174,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 1,
                    "incorrect value for cpu, expected 1, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "SBP                 ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "SBP                 ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 3076,
                    "incorrect value for stack_free, expected 3076, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 10, 0, 124, 9, 0, 0, 52, 2,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 10,
                    "incorrect value for cpu, expected 10, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "manage acq          ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "manage acq          ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 2428,
                    "incorrect value for stack_free, expected 2428, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 116, 114, 97, 99, 107, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 28, 9, 0, 0, 122, 54,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgThreadState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x17,
                    "Incorrect message type, expected 0x17, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu, 0,
                    "incorrect value for cpu, expected 0, is {}",
                    msg.cpu
                );
                assert_eq!(
                    Into::<String>::into(msg.name.clone()),
                    "manage track        ".to_string(),
                    "incorrect value for msg.name, expected string '{}', is '{}'",
                    "manage track        ".to_string(),
                    msg.name
                );
                assert_eq!(
                    msg.stack_free, 2332,
                    "incorrect value for stack_free, expected 2332, is {}",
                    msg.stack_free
                );
            }
            _ => panic!("Invalid message type! Expected a MsgThreadState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
