#ifndef LIBSBP_BOOTLOAD_OPERATORS_H
#define LIBSBP_BOOTLOAD_OPERATORS_H

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/bootload.h instead"
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
static inline int sbp_cmp_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *a, const sbp_msg_bootloader_handshake_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *a, const sbp_msg_bootloader_handshake_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->version, &b->version, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *a, const sbp_msg_bootloader_jump_to_app_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->jump, &b->jump);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *a, const sbp_msg_nap_device_dna_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *a, const sbp_msg_nap_device_dna_resp_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 8 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->dna[i], &b->dna[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *a, const sbp_msg_bootloader_handshake_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->handshake, &b->handshake, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) >= 0;
}
#endif

#endif
