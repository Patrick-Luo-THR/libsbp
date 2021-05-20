#ifndef LIBSBP_INTERNAL_STRING_MULTIPART_H
#define LIBSBP_INTERNAL_STRING_MULTIPART_H

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/string/multipart.h>

#ifdef __cplusplus
extern "C" {
#endif

bool sbp_multipart_string_pack(const sbp_multipart_string_t *s,
                               const sbp_multipart_string_params_t *params,
                               sbp_pack_ctx_t *ctx);
bool sbp_multipart_string_unpack(sbp_multipart_string_t *s,
                                 const sbp_multipart_string_params_t *params,
                                 sbp_unpack_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
