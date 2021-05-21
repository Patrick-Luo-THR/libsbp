#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/linux.h>
#include <libsbp/internal/unpacked/linux.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
static const sbp_unterminated_string_params_t sbp_msg_linux_cpu_state_dep_a_tcmdline_params = 
{
  .max_packed_len = 236
};

  void sbp_msg_linux_cpu_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
}

  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
}

  int sbp_msg_linux_cpu_state_dep_a_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
}

  uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
}

  uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
      }
  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_cpu_state_dep_a_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_cpu_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u8(ctx, &msg->pcpu)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_cpu_state_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_cpu_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u8(ctx, &msg->pcpu)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_cpu_state_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_cpu_state_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *a, const sbp_msg_linux_cpu_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_cpu_state_dep_a_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_mem_state_dep_a_tcmdline_params = 
{
  .max_packed_len = 236
};

  void sbp_msg_linux_mem_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
}

  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
}

  int sbp_msg_linux_mem_state_dep_a_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
}

  uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
}

  uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
      }
  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_mem_state_dep_a_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_mem_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_mem_state_dep_a_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u8(ctx, &msg->pmem)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_mem_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_mem_state_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_mem_state_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_mem_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_mem_state_dep_a_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u8(ctx, &msg->pmem)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_mem_state_dep_a_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_mem_state_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_mem_state_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *a, const sbp_msg_linux_mem_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_mem_state_dep_a_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  return packed_size;
}

bool pack_sbp_msg_linux_sys_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_sys_state_dep_a_t *msg)
{
  if (!pack_u16(ctx, &msg->mem_total)) { return false; }
  if (!pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!pack_u8(ctx, &msg->pmem)) { return false; }
  if (!pack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!pack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!pack_u16(ctx, &msg->pid_count)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_sys_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_sys_state_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_sys_state_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_sys_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_sys_state_dep_a_t *msg)
{
  if (!unpack_u16(ctx, &msg->mem_total)) { return false; }
  if (!unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!unpack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!unpack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!unpack_u16(ctx, &msg->pid_count)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_sys_state_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_sys_state_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *a, const sbp_msg_linux_sys_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->mem_total, &b->mem_total);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_starting, &b->procs_starting);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid_count, &b->pid_count);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_process_socket_counts_tcmdline_params = 
{
  .max_packed_len = 246
};

  void sbp_msg_linux_process_socket_counts_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_process_socket_counts_tcmdline_params);
}

  bool sbp_msg_linux_process_socket_counts_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_process_socket_counts_tcmdline_params);
}

  int sbp_msg_linux_process_socket_counts_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_process_socket_counts_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_process_socket_counts_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_process_socket_counts_tcmdline_params);
      }
  bool sbp_msg_linux_process_socket_counts_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_process_socket_counts_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_process_socket_counts_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_socket_counts_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_process_socket_counts_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_socket_counts_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_process_socket_counts_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_socket_counts_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_process_socket_counts_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_socket_counts_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_process_socket_counts_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_process_socket_counts_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->socket_count);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_process_socket_counts_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_process_socket_counts_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_socket_counts_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u16(ctx, &msg->socket_count)) { return false; }
  if (!pack_u16(ctx, &msg->socket_types)) { return false; }
  if (!pack_u16(ctx, &msg->socket_states)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_process_socket_counts_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_process_socket_counts_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_socket_counts_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_process_socket_counts_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_process_socket_counts_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_socket_counts_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u16(ctx, &msg->socket_count)) { return false; }
  if (!unpack_u16(ctx, &msg->socket_types)) { return false; }
  if (!unpack_u16(ctx, &msg->socket_states)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_process_socket_counts_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_process_socket_counts_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_socket_counts_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_process_socket_counts_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *a, const sbp_msg_linux_process_socket_counts_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_count, &b->socket_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_types, &b->socket_types);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_states, &b->socket_states);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_process_socket_counts_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_process_socket_queues_tcmdline_params = 
{
  .max_packed_len = 180
};

  void sbp_msg_linux_process_socket_queues_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_process_socket_queues_tcmdline_params);
}

  bool sbp_msg_linux_process_socket_queues_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_process_socket_queues_tcmdline_params);
}

  int sbp_msg_linux_process_socket_queues_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_process_socket_queues_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_process_socket_queues_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_process_socket_queues_tcmdline_params);
      }
  bool sbp_msg_linux_process_socket_queues_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_process_socket_queues_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_process_socket_queues_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_socket_queues_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_process_socket_queues_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_socket_queues_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_process_socket_queues_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_socket_queues_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_process_socket_queues_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_socket_queues_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_process_socket_queues_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_process_socket_queues_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->recv_queued);
  packed_size += sbp_packed_size_u16(&msg->send_queued);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += ( 64 * sbp_packed_size_char(&msg->address_of_largest[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_process_socket_queues_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_process_socket_queues_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_socket_queues_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u16(ctx, &msg->recv_queued)) { return false; }
  if (!pack_u16(ctx, &msg->send_queued)) { return false; }
  if (!pack_u16(ctx, &msg->socket_types)) { return false; }
  if (!pack_u16(ctx, &msg->socket_states)) { return false; }
  for (uint8_t i = 0; i < 64; i++)
  {
    if (!pack_char(ctx, &msg->address_of_largest[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_process_socket_queues_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_process_socket_queues_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_socket_queues_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_process_socket_queues_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_process_socket_queues_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_socket_queues_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u16(ctx, &msg->recv_queued)) { return false; }
  if (!unpack_u16(ctx, &msg->send_queued)) { return false; }
  if (!unpack_u16(ctx, &msg->socket_types)) { return false; }
  if (!unpack_u16(ctx, &msg->socket_states)) { return false; }
  for (uint8_t i = 0; i < 64; i++) {
    if (!unpack_char(ctx, &msg->address_of_largest[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_process_socket_queues_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_process_socket_queues_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_socket_queues_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_process_socket_queues_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *a, const sbp_msg_linux_process_socket_queues_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->recv_queued, &b->recv_queued);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->send_queued, &b->send_queued);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_types, &b->socket_types);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->socket_states, &b->socket_states);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 64 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->address_of_largest[i], &b->address_of_largest[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_process_socket_queues_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->avg_queue_depth);
  packed_size += sbp_packed_size_u32(&msg->max_queue_depth);
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_state_counts[0]));
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_type_counts[0]));
  return packed_size;
}

bool pack_sbp_msg_linux_socket_usage_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_socket_usage_t *msg)
{
  if (!pack_u32(ctx, &msg->avg_queue_depth)) { return false; }
  if (!pack_u32(ctx, &msg->max_queue_depth)) { return false; }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!pack_u16(ctx, &msg->socket_state_counts[i])) { return false; }
  }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!pack_u16(ctx, &msg->socket_type_counts[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_linux_socket_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_socket_usage_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_socket_usage_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_socket_usage_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_socket_usage_t *msg)
{
  if (!unpack_u32(ctx, &msg->avg_queue_depth)) { return false; }
  if (!unpack_u32(ctx, &msg->max_queue_depth)) { return false; }
  for (uint8_t i = 0; i < 16; i++) {
    if (!unpack_u16(ctx, &msg->socket_state_counts[i])) { return false; }
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!unpack_u16(ctx, &msg->socket_type_counts[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_socket_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_socket_usage_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_socket_usage_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *a, const sbp_msg_linux_socket_usage_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->avg_queue_depth, &b->avg_queue_depth);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->max_queue_depth, &b->max_queue_depth);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->socket_state_counts[i], &b->socket_state_counts[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->socket_type_counts[i], &b->socket_type_counts[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_process_fd_count_tcmdline_params = 
{
  .max_packed_len = 250
};

  void sbp_msg_linux_process_fd_count_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_process_fd_count_tcmdline_params);
}

  bool sbp_msg_linux_process_fd_count_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_process_fd_count_tcmdline_params);
}

  int sbp_msg_linux_process_fd_count_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_process_fd_count_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_fd_count_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_process_fd_count_tcmdline_params);
}

  uint8_t sbp_msg_linux_process_fd_count_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_process_fd_count_tcmdline_params);
      }
  bool sbp_msg_linux_process_fd_count_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_process_fd_count_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_process_fd_count_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_fd_count_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_process_fd_count_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_process_fd_count_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_process_fd_count_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_fd_count_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_process_fd_count_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_process_fd_count_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_process_fd_count_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_process_fd_count_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->fd_count);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_process_fd_count_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_process_fd_count_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_fd_count_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u16(ctx, &msg->fd_count)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_process_fd_count_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_process_fd_count_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_fd_count_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_process_fd_count_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_process_fd_count_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_fd_count_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u16(ctx, &msg->fd_count)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_process_fd_count_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_process_fd_count_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_fd_count_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_process_fd_count_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *a, const sbp_msg_linux_process_fd_count_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->fd_count, &b->fd_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_process_fd_count_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_sequence_string_params_t sbp_msg_linux_process_fd_summary_tmost_opened_params = 
{
  .max_packed_len = 251
  ,.terminator = 0
};

  void sbp_msg_linux_process_fd_summary_t_most_opened_init(sbp_sequence_string_t *s)
{
  sbp_sequence_string_init(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_valid(const sbp_sequence_string_t *s)
{
  return sbp_sequence_string_valid(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
}

  int sbp_msg_linux_process_fd_summary_t_most_opened_strcmp(const sbp_sequence_string_t *a, const sbp_sequence_string_t *b)
{
  return sbp_sequence_string_strcmp(a, b, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
}

  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_packed_len(const sbp_sequence_string_t *s)
{
  return sbp_sequence_string_packed_len(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
}

  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_space_remaining(const sbp_sequence_string_t *s)
{
  return sbp_sequence_string_space_remaining(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
      }
  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_count_sections(const sbp_sequence_string_t *s)
{
  return sbp_sequence_string_count_sections(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section(sbp_sequence_string_t *s, const char *new_str)
{
  return sbp_sequence_string_add_section(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, new_str);
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_printf(sbp_sequence_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_sequence_string_add_section_vprintf(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_vprintf(sbp_sequence_string_t *s, const char *fmt, va_list ap)
{
  return sbp_sequence_string_add_section_vprintf(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, fmt, ap);
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_append(sbp_sequence_string_t *s, const char *str)
{
  return sbp_sequence_string_append(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, str);
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_append_printf(sbp_sequence_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_sequence_string_append_vprintf(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_process_fd_summary_t_most_opened_append_vprintf(sbp_sequence_string_t *s, const char *fmt, va_list ap)
{
  return sbp_sequence_string_append_vprintf(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, fmt, ap);
}

  const char *sbp_msg_linux_process_fd_summary_t_most_opened_get_section(sbp_sequence_string_t *s, uint8_t section)
{
  return sbp_sequence_string_get_section(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, section);
}

  uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_section_strlen(sbp_sequence_string_t *s, uint8_t section)
{
  return sbp_sequence_string_section_strlen(s, &sbp_msg_linux_process_fd_summary_tmost_opened_params, section);
}

size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sys_fd_count);
  packed_size += sbp_sequence_string_packed_len(&msg->most_opened, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
  return packed_size;
}

bool pack_sbp_msg_linux_process_fd_summary_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_fd_summary_t *msg)
{
  if (!pack_u32(ctx, &msg->sys_fd_count)) { return false; }
  if (!sbp_sequence_string_pack(&msg->most_opened, &sbp_msg_linux_process_fd_summary_tmost_opened_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_process_fd_summary_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_process_fd_summary_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_process_fd_summary_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_process_fd_summary_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_fd_summary_t *msg)
{
  if (!unpack_u32(ctx, &msg->sys_fd_count)) { return false; }
  if (!sbp_sequence_string_unpack(&msg->most_opened, &sbp_msg_linux_process_fd_summary_tmost_opened_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_process_fd_summary_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_process_fd_summary_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_process_fd_summary_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *a, const sbp_msg_linux_process_fd_summary_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sys_fd_count, &b->sys_fd_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_sequence_string_strcmp(&a->most_opened, &b->most_opened, &sbp_msg_linux_process_fd_summary_tmost_opened_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_cpu_state_tcmdline_params = 
{
  .max_packed_len = 231
};

  void sbp_msg_linux_cpu_state_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_cpu_state_tcmdline_params);
}

  bool sbp_msg_linux_cpu_state_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_cpu_state_tcmdline_params);
}

  int sbp_msg_linux_cpu_state_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_cpu_state_tcmdline_params);
}

  uint8_t sbp_msg_linux_cpu_state_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_cpu_state_tcmdline_params);
}

  uint8_t sbp_msg_linux_cpu_state_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_cpu_state_tcmdline_params);
      }
  bool sbp_msg_linux_cpu_state_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_cpu_state_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_cpu_state_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_cpu_state_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_cpu_state_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_cpu_state_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_cpu_state_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_cpu_state_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_cpu_state_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_cpu_state_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_cpu_state_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_cpu_state_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_cpu_state_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_cpu_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_cpu_state_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!pack_u32(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_cpu_state_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_cpu_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_cpu_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_cpu_state_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_cpu_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_cpu_state_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!unpack_u32(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_cpu_state_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_cpu_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_cpu_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_cpu_state_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *a, const sbp_msg_linux_cpu_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_cpu_state_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_unterminated_string_params_t sbp_msg_linux_mem_state_tcmdline_params = 
{
  .max_packed_len = 231
};

  void sbp_msg_linux_mem_state_t_cmdline_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_linux_mem_state_tcmdline_params);
}

  bool sbp_msg_linux_mem_state_t_cmdline_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_linux_mem_state_tcmdline_params);
}

  int sbp_msg_linux_mem_state_t_cmdline_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_linux_mem_state_tcmdline_params);
}

  uint8_t sbp_msg_linux_mem_state_t_cmdline_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_linux_mem_state_tcmdline_params);
}

  uint8_t sbp_msg_linux_mem_state_t_cmdline_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_linux_mem_state_tcmdline_params);
      }
  bool sbp_msg_linux_mem_state_t_cmdline_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_linux_mem_state_tcmdline_params, new_str);
  }

  bool sbp_msg_linux_mem_state_t_cmdline_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_linux_mem_state_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_linux_mem_state_t_cmdline_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_linux_mem_state_tcmdline_params, fmt, ap);
  }

  bool sbp_msg_linux_mem_state_t_cmdline_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_mem_state_tcmdline_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_linux_mem_state_t_cmdline_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_linux_mem_state_tcmdline_params, fmt, ap);
}

  const char *sbp_msg_linux_mem_state_t_cmdline_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_linux_mem_state_tcmdline_params);
}

size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, &sbp_msg_linux_mem_state_tcmdline_params);
  return packed_size;
}

bool pack_sbp_msg_linux_mem_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_mem_state_t *msg)
{
  if (!pack_u8(ctx, &msg->index)) { return false; }
  if (!pack_u16(ctx, &msg->pid)) { return false; }
  if (!pack_u8(ctx, &msg->pmem)) { return false; }
  if (!pack_u32(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, &sbp_msg_linux_mem_state_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_mem_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_mem_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_mem_state_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_mem_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_mem_state_t *msg)
{
  if (!unpack_u8(ctx, &msg->index)) { return false; }
  if (!unpack_u16(ctx, &msg->pid)) { return false; }
  if (!unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!unpack_u32(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, &sbp_msg_linux_mem_state_tcmdline_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_mem_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_mem_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_mem_state_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *a, const sbp_msg_linux_mem_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid, &b->pid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 15 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, &sbp_msg_linux_mem_state_tcmdline_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_linux_sys_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_sys_state_t *msg)
{
  if (!pack_u16(ctx, &msg->mem_total)) { return false; }
  if (!pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!pack_u8(ctx, &msg->pmem)) { return false; }
  if (!pack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!pack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!pack_u16(ctx, &msg->pid_count)) { return false; }
  if (!pack_u32(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_linux_sys_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_linux_sys_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_linux_sys_state_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_linux_sys_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_sys_state_t *msg)
{
  if (!unpack_u16(ctx, &msg->mem_total)) { return false; }
  if (!unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!unpack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!unpack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!unpack_u16(ctx, &msg->pid_count)) { return false; }
  if (!unpack_u32(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_linux_sys_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_linux_sys_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_linux_sys_state_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *a, const sbp_msg_linux_sys_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->mem_total, &b->mem_total);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pcpu, &b->pcpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pmem, &b->pmem);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_starting, &b->procs_starting);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pid_count, &b->pid_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
