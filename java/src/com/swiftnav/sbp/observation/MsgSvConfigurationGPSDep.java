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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SV_CONFIGURATION_GPS_DEP (0x0091).
 *
 * <p>You can have MSG_SV_CONFIGURATION_GPS_DEP inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */
public class MsgSvConfigurationGPSDep extends SBPMessage {
    public static final int TYPE = 0x0091;

    /** Navigation Message Correction Table Validity Time */
    public GPSTimeSec t_nmct;

    /** L2C capability mask, SV32 bit being MSB, SV1 bit being LSB */
    public long l2c_mask;

    public MsgSvConfigurationGPSDep(int sender) {
        super(sender, TYPE);
    }

    public MsgSvConfigurationGPSDep() {
        super(TYPE);
    }

    public MsgSvConfigurationGPSDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_nmct = new GPSTimeSec().parse(parser);
        l2c_mask = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        t_nmct.build(builder);
        builder.putU32(l2c_mask);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_nmct", t_nmct.toJSON());
        obj.put("l2c_mask", l2c_mask);
        return obj;
    }
}
