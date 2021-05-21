#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/orientation.h>
#include <libsbp/internal/unpacked/orientation.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_heading_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_heading_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u32(ctx, &msg->heading)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_heading_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_heading_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_heading_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_heading_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_heading_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u32(ctx, &msg->heading)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_heading_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_heading_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_heading_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *a, const sbp_msg_baseline_heading_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->heading, &b->heading);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->w);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->w_accuracy);
  packed_size += sbp_packed_size_float(&msg->x_accuracy);
  packed_size += sbp_packed_size_float(&msg->y_accuracy);
  packed_size += sbp_packed_size_float(&msg->z_accuracy);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_orient_quat_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_quat_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->w)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->w_accuracy)) { return false; }
  if (!pack_float(ctx, &msg->x_accuracy)) { return false; }
  if (!pack_float(ctx, &msg->y_accuracy)) { return false; }
  if (!pack_float(ctx, &msg->z_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_orient_quat_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_orient_quat_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_orient_quat_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_orient_quat_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_quat_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->w)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->w_accuracy)) { return false; }
  if (!unpack_float(ctx, &msg->x_accuracy)) { return false; }
  if (!unpack_float(ctx, &msg->y_accuracy)) { return false; }
  if (!unpack_float(ctx, &msg->z_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_orient_quat_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_orient_quat_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_orient_quat_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *a, const sbp_msg_orient_quat_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->w, &b->w);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->w_accuracy, &b->w_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->x_accuracy, &b->x_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->y_accuracy, &b->y_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->z_accuracy, &b->z_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->roll);
  packed_size += sbp_packed_size_s32(&msg->pitch);
  packed_size += sbp_packed_size_s32(&msg->yaw);
  packed_size += sbp_packed_size_float(&msg->roll_accuracy);
  packed_size += sbp_packed_size_float(&msg->pitch_accuracy);
  packed_size += sbp_packed_size_float(&msg->yaw_accuracy);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_orient_euler_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_euler_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->roll)) { return false; }
  if (!pack_s32(ctx, &msg->pitch)) { return false; }
  if (!pack_s32(ctx, &msg->yaw)) { return false; }
  if (!pack_float(ctx, &msg->roll_accuracy)) { return false; }
  if (!pack_float(ctx, &msg->pitch_accuracy)) { return false; }
  if (!pack_float(ctx, &msg->yaw_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_orient_euler_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_orient_euler_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_orient_euler_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_orient_euler_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_euler_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->roll)) { return false; }
  if (!unpack_s32(ctx, &msg->pitch)) { return false; }
  if (!unpack_s32(ctx, &msg->yaw)) { return false; }
  if (!unpack_float(ctx, &msg->roll_accuracy)) { return false; }
  if (!unpack_float(ctx, &msg->pitch_accuracy)) { return false; }
  if (!unpack_float(ctx, &msg->yaw_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_orient_euler_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_orient_euler_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_orient_euler_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *a, const sbp_msg_orient_euler_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->roll, &b->roll);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pitch, &b->pitch);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->yaw, &b->yaw);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->roll_accuracy, &b->roll_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->pitch_accuracy, &b->pitch_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->yaw_accuracy, &b->yaw_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_angular_rate_t(sbp_pack_ctx_t *ctx, const sbp_msg_angular_rate_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_angular_rate_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_angular_rate_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_angular_rate_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_angular_rate_t(sbp_unpack_ctx_t *ctx, sbp_msg_angular_rate_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_angular_rate_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_angular_rate_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_angular_rate_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *a, const sbp_msg_angular_rate_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
