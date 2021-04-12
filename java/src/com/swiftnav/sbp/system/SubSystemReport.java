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

package com.swiftnav.sbp.system;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class SubSystemReport extends SBPStruct {
    
    /** Identity of reporting subsystem */
    public int component;
    
    /** Generic form status report */
    public int generic;
    
    /** Subsystem specific status code */
    public int specific;
    

    public SubSystemReport () {}

    @Override
    public SubSystemReport parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        component = parser.getU16();
        generic = parser.getU8();
        specific = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU16(component);
        builder.putU8(generic);
        builder.putU8(specific);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("component", component);
        obj.put("generic", generic);
        obj.put("specific", specific);
        return obj;
    }
}