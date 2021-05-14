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
 * Automatically generated from yaml/swiftnav/sbp/user.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup user User
 *
 *  * Messages reserved for use by the user.
 * \{ */

#ifndef LIBSBP_USER_MESSAGES_H
#define LIBSBP_USER_MESSAGES_H

#include "common.h"

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** User data
 *
 * This message can contain any application specific user data up to a
 * maximum length of 255 bytes per message.
 */
#define SBP_MSG_USER_DATA 0x0800
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  u8 contents[0]; /**< User data payload */
} msg_user_data_t;
#endif
 

/** \} */
static inline void static_asserts_for_module_MSG_USER_DATA(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_user_data_t, contents ) == 0, "Offset of contents in msg_user_data_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_user_data_t, contents ) == 0, offset_of_contents_in_msg_user_data_t_is_incorrect)
#endif
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_USER_MESSAGES_H */
