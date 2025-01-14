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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_orientation_msg_orient_quat() {
    {
        let mut payload = Cursor::new(vec![
            85, 32, 2, 66, 0, 37, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0, 0, 0, 0,
            64, 64, 0, 0, 128, 64, 0, 0, 0, 65, 0, 0, 64, 64, 1, 186, 6,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgOrientQuat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x220,
                    "Incorrect message type, expected 0x220, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(msg.w, 3, "incorrect value for w, expected 3, is {}", msg.w);
                assert!(
                    msg.w_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for w_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.w_accuracy
                );
                assert_eq!(msg.x, 7, "incorrect value for x, expected 7, is {}", msg.x);
                assert!(
                    msg.x_accuracy.almost_eq(4.00000000000000000e+00),
                    "incorrect value for x_accuracy, expected 4.00000000000000000e+00, is {:e}",
                    msg.x_accuracy
                );
                assert_eq!(msg.y, 8, "incorrect value for y, expected 8, is {}", msg.y);
                assert!(
                    msg.y_accuracy.almost_eq(8.00000000000000000e+00),
                    "incorrect value for y_accuracy, expected 8.00000000000000000e+00, is {:e}",
                    msg.y_accuracy
                );
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
                assert!(
                    msg.z_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for z_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.z_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientQuat"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
