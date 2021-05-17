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

package com.swiftnav.sbp.linux;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_LINUX_PROCESS_SOCKET_QUEUES (0x7F04).
 *
 * You can have MSG_LINUX_PROCESS_SOCKET_QUEUES inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Top 10 list of sockets with deep queues. */

public class MsgLinuxProcessSocketQueues extends SBPMessage {
    public static final int TYPE = 0x7F04;

    
    /** sequence of this status message, values from 0-9 */
    public int index;
    
    /** the PID of the process in question */
    public int pid;
    
    /** the total amount of receive data queued for this process */
    public int recv_queued;
    
    /** the total amount of send data queued for this process */
    public int send_queued;
    
    /** A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
    public int socket_types;
    
    /** A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
    public int socket_states;
    
    /** Address of the largest queue, remote or local depending on the directionality
of the connection.
 */
    public String address_of_largest;
    
    /** the command line of the process in question */
    public String cmdline;
    

    public MsgLinuxProcessSocketQueues (int sender) { super(sender, TYPE); }
    public MsgLinuxProcessSocketQueues () { super(TYPE); }
    public MsgLinuxProcessSocketQueues (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU8();
        pid = parser.getU16();
        recv_queued = parser.getU16();
        send_queued = parser.getU16();
        socket_types = parser.getU16();
        socket_states = parser.getU16();
        address_of_largest = parser.getString(64);
        cmdline = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(index);
        builder.putU16(pid);
        builder.putU16(recv_queued);
        builder.putU16(send_queued);
        builder.putU16(socket_types);
        builder.putU16(socket_states);
        builder.putString(address_of_largest, 64);
        builder.putString(cmdline);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        obj.put("pid", pid);
        obj.put("recv_queued", recv_queued);
        obj.put("send_queued", send_queued);
        obj.put("socket_types", socket_types);
        obj.put("socket_states", socket_states);
        obj.put("address_of_largest", address_of_largest);
        obj.put("cmdline", cmdline);
        return obj;
    }
}