/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_AGE_CORRECTIONS (0x0210).
 *
 * <p>You can have MSG_AGE_CORRECTIONS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the Age of the corrections used for the current Differential solution.
 */
public class MsgAgeCorrections extends SBPMessage {
    public static final int TYPE = 0x0210;

    /** GPS Time of Week */
    public long tow;

    /** Age of the corrections (0xFFFF indicates invalid) */
    public int age;

    public MsgAgeCorrections(int sender) {
        super(sender, TYPE);
    }

    public MsgAgeCorrections() {
        super(TYPE);
    }

    public MsgAgeCorrections(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        age = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU16(age);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("age", age);
        return obj;
    }
}
