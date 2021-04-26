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
 * Automatically generated from yaml/swiftnav/sbp/flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup flash Flash
 *
 *  * Messages for reading/writing the device's onboard flash memory. Many
 * of these messages target specific flash memory peripherals used in
 * Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
 * configuration flash from Piksi 2.3.1.  This module does not apply 
 * to Piksi Multi.
 * \{ */

#ifndef LIBSBP_PACKED_FLASH_MESSAGES_H
#define LIBSBP_PACKED_FLASH_MESSAGES_H

#include <libsbp/common.h>

SBP_PACK_START


#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Program flash addresses
 *
 * The flash program message programs a set of addresses of either
 * the STM or M25 flash. The device replies with either a
 * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
 * on success, or FLASH_INVALID_LEN (2) if the maximum write size
 * is exceeded. Note that the sector-containing addresses must be
 * erased before addresses can be programmed.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_FLASH_PROGRAM           0x00E6
  
  /** 
   * Target flags 
   */
  u8 target;       
  
  /** 
   * Starting address offset to program [bytes] 
   */
  u8 addr_start[3];
  
  /** 
    * Length of set of addresses to program, counting up from
 * starting address [bytes] 
   */
  u8 addr_len;     
  
  /** 
   * Data to program addresses with, with length N=addr_len 
   */
  u8 data[0];      
  
} msg_flash_program_t;


#define SBP_FLASH_DONE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_CODE_GET(flags) \
                             (((flags) >> SBP_FLASH_DONE_RESPONSE_CODE_SHIFT) \
                             & SBP_FLASH_DONE_RESPONSE_CODE_MASK)
#define SBP_FLASH_DONE_RESPONSE_CODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_DONE_RESPONSE_CODE_MASK)) \
                             << (SBP_FLASH_DONE_RESPONSE_CODE_SHIFT)));} while(0)
                             

#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_OK (0)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_FLASH (1)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_LEN (2)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_ADDR (3)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_RANGE (4)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_SECTOR (5)
/** Flash response message (host <= device).
 *
 * This message defines success or failure codes for a variety of
 * flash memory requests from the host to the device. Flash read
 * and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_FLASH_DONE              0x00E0
  
  /** 
   * Response flags 
   */
  u8 response;   
  
} msg_flash_done_t;


#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Read STM or M25 flash address request (host => device).
 *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_FLASH_READ_REQ          0x00E7
  
  /** 
   * Target flags 
   */
  u8 target;       
  
  /** 
   * Starting address offset to read from [bytes] 
   */
  u8 addr_start[3];
  
  /** 
    * Length of set of addresses to read, counting up from
 * starting address [bytes] 
   */
  u8 addr_len;     
  
} msg_flash_read_req_t;


#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Read STM or M25 flash address response (host <= device).
 *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_FLASH_READ_RESP         0x00E1
  
  /** 
   * Target flags 
   */
  u8 target;       
  
  /** 
   * Starting address offset to read from [bytes] 
   */
  u8 addr_start[3];
  
  /** 
    * Length of set of addresses to read, counting up from
 * starting address [bytes] 
   */
  u8 addr_len;     
  
} msg_flash_read_resp_t;


#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Erase sector of device flash memory (host => device).
 *
 * The flash erase message from the host erases a sector of either
 * the STM or M25 onboard flash memory. The device will reply with a
 * MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
 * on success or FLASH_INVALID_FLASH (1) if the flash specified is
 * invalid.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_FLASH_ERASE             0x00E2
  
  /** 
   * Target flags 
   */
  u8 target;       
  
  /** 
    * Flash sector number to erase (0-11 for the STM, 0-15 for
 * the M25) 
   */
  u32 sector_num;   
  
} msg_flash_erase_t;


/** Lock sector of STM flash memory (host => device)
 *
 * The flash lock message locks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_STM_FLASH_LOCK_SECTOR   0x00E3
  
  /** 
   * Flash sector number to lock 
   */
  u32 sector;   
  
} msg_stm_flash_lock_sector_t;


/** Unlock sector of STM flash memory (host => device)
 *
 * The flash unlock message unlocks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
  
  /** 
   * Flash sector number to unlock 
   */
  u32 sector;   
  
} msg_stm_flash_unlock_sector_t;


/** Read device's hardcoded unique ID request (host => device)

 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_STM_UNIQUE_ID_REQ       0x00E8
  
} msg_stm_unique_id_req_t;


/** Read device's hardcoded unique ID response (host <= device)

 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload..
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_STM_UNIQUE_ID_RESP      0x00E5
  
  /** 
   * Device unique ID 
   */
  u8 stm_id[12];
  
} msg_stm_unique_id_resp_t;


/** Write M25 flash status register (host => device)
 *
 * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message.
 */
typedef struct SBP_ATTR_PACKED {
#define SBP_MSG_M25_FLASH_WRITE_STATUS  0x00F3
  
  /** 
   * Byte to write to the M25 flash status register 
   */
  u8 status[1];
  
} msg_m25_flash_write_status_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_FLASH_MESSAGES_H */