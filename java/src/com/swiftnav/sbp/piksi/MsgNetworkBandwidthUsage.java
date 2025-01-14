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
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).
 *
 * <p>You can have MSG_NETWORK_BANDWIDTH_USAGE inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>The bandwidth usage, a list of usage by interface.
 */
public class MsgNetworkBandwidthUsage extends SBPMessage {
    public static final int TYPE = 0x00BD;

    /** Usage measurement array */
    public NetworkUsage[] interfaces;

    public MsgNetworkBandwidthUsage(int sender) {
        super(sender, TYPE);
    }

    public MsgNetworkBandwidthUsage() {
        super(TYPE);
    }

    public MsgNetworkBandwidthUsage(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        interfaces = parser.getArray(NetworkUsage.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArray(interfaces);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("interfaces", SBPStruct.toJSONArray(interfaces));
        return obj;
    }
}
