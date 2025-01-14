//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_settings_msg_settings_read_by_index_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 78, 0, 0, 116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114,
            97, 100, 105, 111, 0, 99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110,
            95, 115, 116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
            53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65, 84, 38, 87,
            44, 65, 84, 90, 0, 248, 233,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.index, 0,
                    "incorrect value for index, expected 0, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.to_string(),
                    "telemetry_radio configuration_string AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ "
                        .to_string(),
                    "incorrect value for msg.setting, expected string '{}', is '{}'",
                    "telemetry_radio configuration_string AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ "
                        .to_string(),
                    msg.setting
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 1, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111,
            100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0,
            167, 243,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.index, 1,
                    "incorrect value for index, expected 1, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.to_string(),
                    "uart_ftdi mode SBP enum:SBP,NMEA ".to_string(),
                    "incorrect value for msg.setting, expected string '{}', is '{}'",
                    "uart_ftdi mode SBP enum:SBP,NMEA ".to_string(),
                    msg.setting
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 2, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98,
            112, 95, 109, 101, 115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51,
            53, 0, 4, 56,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.index, 2,
                    "incorrect value for index, expected 2, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.to_string(),
                    "uart_ftdi sbp_message_mask 65535 ".to_string(),
                    "incorrect value for msg.setting, expected string '{}', is '{}'",
                    "uart_ftdi sbp_message_mask 65535 ".to_string(),
                    msg.setting
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 29, 3, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97,
            117, 100, 114, 97, 116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0, 242, 146,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.index, 3,
                    "incorrect value for index, expected 3, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.to_string(),
                    "uart_ftdi baudrate 1000000 ".to_string(),
                    "incorrect value for msg.setting, expected string '{}', is '{}'",
                    "uart_ftdi baudrate 1000000 ".to_string(),
                    msg.setting
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 36, 4, 0, 117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109,
            111, 100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69,
            65, 0, 22, 4,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.index, 4,
                    "incorrect value for index, expected 4, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.to_string(),
                    "uart_uarta mode SBP enum:SBP,NMEA ".to_string(),
                    "incorrect value for msg.setting, expected string '{}', is '{}'",
                    "uart_uarta mode SBP enum:SBP,NMEA ".to_string(),
                    msg.setting
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
