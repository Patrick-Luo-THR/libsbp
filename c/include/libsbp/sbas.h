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

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup sbas Sbas
 *
 * * SBAS data
 * \{ */

#ifndef LIBSBP_PACKED_SBAS_MESSAGES_H
#define LIBSBP_PACKED_SBAS_MESSAGES_H

#include <libsbp/common.h>
#include <libsbp/gnss.h>

SBP_PACK_START

/** Raw SBAS data
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_SBAS_RAW 0x7777
typedef struct SBP_ATTR_PACKED
{

  /**
   * GNSS signal identifier.
   */
  sbp_gnss_signal_t sid;

  /**
   * GPS time-of-week at the start of the data block. [ms]
   */
  u32 tow;

  /**
   * SBAS message type (0-63)
   */
  u8 message_type;

  /**
   * Raw SBAS data field of 212 bits (last byte padded with zeros).
   */
  u8 data[27];

} msg_sbas_raw_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_SBAS_MESSAGES_H */