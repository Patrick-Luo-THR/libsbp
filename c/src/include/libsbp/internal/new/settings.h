/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_INTERNAL_NEW_SETTINGS_H
#define LIBSBP_INTERNAL_NEW_SETTINGS_H

#include <stdbool.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/new/settings.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_save_t(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_settings_save_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_save_t(sbp_decode_ctx_t *ctx,
                                    sbp_msg_settings_save_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_write_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_settings_write_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_write_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_settings_write_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_write_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_write_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_write_resp_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_settings_write_resp_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_read_req_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_settings_read_req_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_read_req_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_settings_read_req_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_read_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_read_resp_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_settings_read_resp_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_read_by_index_req_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_req_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_read_by_index_req_t(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_req_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_read_by_index_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_read_by_index_resp_t(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_read_by_index_done_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_read_by_index_done_t(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_register_t(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_settings_register_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_register_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_settings_register_t *msg);

/**
 * Internal function to encode an SBP type to a buffer
 *
 * @param ctx Encode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool encode_sbp_msg_settings_register_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_settings_register_resp_t *msg);

/**
 * Internal function to decode an SBP type from a buffer
 *
 * @param ctx Decode context
 * @param msg SBP type instance
 * @return true on success, false otherwise
 */
bool decode_sbp_msg_settings_register_resp_t(
    sbp_decode_ctx_t *ctx, sbp_msg_settings_register_resp_t *msg);

#ifdef __cplusplus
}
#endif

#endif
