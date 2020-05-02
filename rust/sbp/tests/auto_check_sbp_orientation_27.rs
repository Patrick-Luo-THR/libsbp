//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_orientation_27() {
    {
        let payload: Vec<u8> = vec![
            85, 34, 2, 66, 0, 17, 2, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 2, 0, 0, 0, 0, 88, 70,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new(std::io::Cursor::new(payload));
        let msg_result = parser.parse();
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAngularRate(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x222,
                    "Incorrect message type, expected 0x222, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 2, "incorrect value for x, expected 2, is {}", msg.x);
                assert_eq!(msg.y, 5, "incorrect value for y, expected 5, is {}", msg.y);
                assert_eq!(msg.z, 2, "incorrect value for z, expected 2, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgAngularRate"),
        };

        let payload = parser.into_inner().into_inner();
        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
