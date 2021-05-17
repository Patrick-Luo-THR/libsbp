#ifndef LIBSBP_SBAS_OPERATORS_H
#define LIBSBP_SBAS_OPERATORS_H

#ifndef LIBSBP_SBAS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/sbas.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *a, const sbp_msg_sbas_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->message_type, &b->message_type);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 27 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) >= 0;
}
#endif

#endif