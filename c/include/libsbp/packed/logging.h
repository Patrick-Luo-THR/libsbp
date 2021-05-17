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
 * Automatically generated from yaml/swiftnav/sbp/logging.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup logging Logging
 *
 *  * Logging and debugging messages from the device.
 * \{ */

#ifndef LIBSBP_PACKED_LOGGING_MESSAGES_H
#define LIBSBP_PACKED_LOGGING_MESSAGES_H

#include <libsbp/common.h>

SBP_PACK_START


#define SBP_LOG_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LOGGING_LEVEL_GET(flags) \
                             (((flags) >> SBP_LOG_LOGGING_LEVEL_SHIFT) \
                             & SBP_LOG_LOGGING_LEVEL_MASK)
#define SBP_LOG_LOGGING_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LOG_LOGGING_LEVEL_MASK)) \
                             << (SBP_LOG_LOGGING_LEVEL_SHIFT)));} while(0)
                             

#define SBP_LOG_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LOGGING_LEVEL_DEBUG (7)
/** Plaintext logging messages with levels
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_LOG       0x0401
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Logging level 
   */
  u8 level;   
  
  /** 
   * Human-readable string 
   */
  char text[0]; 
  
} msg_log_t;


/** Wrapper for FWD a separate stream of information over SBP
 *
 * This message provides the ability to forward messages over SBP.  This may take the form
 * of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
 * another protocol with SBP.
 * 
 * The source identifier indicates from what interface a forwarded stream derived.
 * The protocol identifier identifies what the expected protocol the forwarded msg contains.
 * Protocol 0 represents SBP and the remaining values are implementation defined.
 */
#define SBP_MSG_FWD       0x0402
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * source identifier 
   */
  u8 source;        
  
  /** 
   * protocol identifier 
   */
  u8 protocol;      
  
  /** 
   * variable length wrapped binary message 
   */
  char fwd_payload[0];
  
} msg_fwd_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_PRINT_DEP 0x0010
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * Human-readable string 
   */
  char text[0];
  
} msg_print_dep_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_LOGGING_MESSAGES_H */