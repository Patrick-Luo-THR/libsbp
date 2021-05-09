#ifndef LIBSBP_LOGGING_OPERATORS_H
#define LIBSBP_LOGGING_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/logging.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  (void)a;
  (void)b;

  if (a.level != b.level)
  {
    return false;
  }
  if (a.text_count != b.text_count)
  {
    return false;
  }
  for (size_t text_idx = 0; text_idx < (size_t)a.text_count; text_idx++)
  {

    if (a.text[text_idx] != b.text[text_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  (void)a;
  (void)b;

  if (a.source != b.source)
  {
    return false;
  }

  if (a.protocol != b.protocol)
  {
    return false;
  }
  if (a.fwd_payload_count != b.fwd_payload_count)
  {
    return false;
  }
  for (size_t fwd_payload_idx = 0; fwd_payload_idx < (size_t)a.fwd_payload_count; fwd_payload_idx++)
  {

    if (a.fwd_payload[fwd_payload_idx] != b.fwd_payload[fwd_payload_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.text_count != b.text_count)
  {
    return false;
  }
  for (size_t text_idx = 0; text_idx < (size_t)a.text_count; text_idx++)
  {

    if (a.text[text_idx] != b.text[text_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  return !(a == b);
}
#endif

#endif
