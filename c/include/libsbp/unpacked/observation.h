#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/gnss.h>
/** Header for observation message.
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sbp_gps_time_t t;
  u8 n_obs;
} sbp_observation_header_t;



/** GNSS doppler measurement.
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 i;
  u8 f;
} sbp_doppler_t;



#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT (7u)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_NO_EXCLUSION (0)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MEASUREMENT_WAS_EXCLUDED_BY_SPP_RAIM_USE_WITH_CARE (1)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT (3u)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_INVALID_DOPPLER_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_VALID_DOPPLER_MEASUREMENT (1)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT (2u)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_UNRESOLVED (0)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_RESOLVED (1)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT (1u)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_INVALID_CARRIER_PHASE_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_VALID_CARRIER_PHASE_MEASUREMENT (1)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT (0u)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_GET(flags) \
                             (((flags) >> SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT) \
                             & SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK)) \
                             << (SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT)));} while(0)
                             

#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_INVALID_PSEUDORANGE_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_VALID_PSEUDORANGE_MEASUREMENT_AND_COARSE_TOW_DECODED (1)
/** GNSS observations for a particular satellite signal.
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 P;
  sbp_carrier_phase_t L;
  sbp_doppler_t D;
  u8 cn0;
  u8 lock;
  u8 flags;
  sbp_sbp_gnss_signal_t sid;
} sbp_packed_obs_content_t;



#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT (4u)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_VALID_PHASE_CORRECTIONS (0)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_DO_NOT_USE_PHASE_CORRECTIONS (1)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT (3u)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_VALID_CODE_CORRECTIONS (0)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_DO_NOT_USE_CODE_CORRECTIONS (1)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT (2u)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_FULL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_FULL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT (1u)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT (0u)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_GET(flags) \
                             (((flags) >> SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT) \
                             & SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK)) \
                             << (SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT)));} while(0)
                             

#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_DO_NOT_USE_SIGNAL (0)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_VALID_SIGNAL (1)
/** Network correction for a particular satellite signal.
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 P;
  sbp_carrier_phase_t L;
  u8 lock;
  u8 flags;
  sbp_sbp_gnss_signal_t sid;
  u16 iono_std;
  u16 tropo_std;
  u16 range_std;
} sbp_packed_osr_content_t;



/** GPS satellite observations
 *
((m.desc|commentify)))
 */
#define SBP_MSG_OBS                      0x004A
typedef struct {
  sbp_observation_header_t header;
  sbp_packed_obs_content_t obs[14];
  u8 n_obs;
} sbp_msg_obs_t;



/** Base station position
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASE_POS_LLH             0x0044
typedef struct {
  double lat;
  double lon;
  double height;
} sbp_msg_base_pos_llh_t;



/** Base station position in ECEF
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASE_POS_ECEF            0x0048
typedef struct {
  double x;
  double y;
  double z;
} sbp_msg_base_pos_ecef_t;



typedef struct {
  sbp_sbp_gnss_signal_t sid;
  sbp_gps_time_sec_t toe;
  float ura;
  u32 fit_interval;
  u8 valid;
  u8 health_bits;
} sbp_ephemeris_common_content_t;



typedef struct {
  sbp_sbp_gnss_signal_t sid;
  sbp_gps_time_sec_t toe;
  double ura;
  u32 fit_interval;
  u8 valid;
  u8 health_bits;
} sbp_ephemeris_common_content_dep_b_t;



typedef struct {
  sbp_gnss_signal_dep_t sid;
  sbp_gps_time_dep_t toe;
  double ura;
  u32 fit_interval;
  u8 valid;
  u8 health_bits;
} sbp_ephemeris_common_content_dep_a_t;



/** Satellite broadcast ephemeris for GPS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E      0x0081
typedef struct {
  sbp_ephemeris_common_content_dep_a_t common;
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  sbp_gps_time_dep_t toc;
  u8 iode;
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_e_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_F      0x0086
typedef struct {
  sbp_ephemeris_common_content_dep_b_t common;
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  sbp_gps_time_sec_t toc;
  u8 iode;
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_f_t;



/** Satellite broadcast ephemeris for GPS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GPS            0x008A
typedef struct {
  sbp_ephemeris_common_content_t common;
  float tgd;
  float c_rs;
  float c_rc;
  float c_uc;
  float c_us;
  float c_ic;
  float c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  float af0;
  float af1;
  float af2;
  sbp_gps_time_sec_t toc;
  u8 iode;
  u16 iodc;
} sbp_msg_ephemeris_gps_t;



/** Satellite broadcast ephemeris for QZSS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_QZSS           0x008E
typedef struct {
  sbp_ephemeris_common_content_t common;
  float tgd;
  float c_rs;
  float c_rc;
  float c_uc;
  float c_us;
  float c_ic;
  float c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  float af0;
  float af1;
  float af2;
  sbp_gps_time_sec_t toc;
  u8 iode;
  u16 iodc;
} sbp_msg_ephemeris_qzss_t;



/** Satellite broadcast ephemeris for BDS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_BDS            0x0089
typedef struct {
  sbp_ephemeris_common_content_t common;
  float tgd1;
  float tgd2;
  float c_rs;
  float c_rc;
  float c_uc;
  float c_us;
  float c_ic;
  float c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  float af1;
  float af2;
  sbp_gps_time_sec_t toc;
  u8 iode;
  u16 iodc;
} sbp_msg_ephemeris_bds_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GAL_DEP_A      0x0095
typedef struct {
  sbp_ephemeris_common_content_t common;
  float bgd_e1e5a;
  float bgd_e1e5b;
  float c_rs;
  float c_rc;
  float c_uc;
  float c_us;
  float c_ic;
  float c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  float af2;
  sbp_gps_time_sec_t toc;
  u16 iode;
  u16 iodc;
} sbp_msg_ephemeris_gal_dep_a_t;



/** Satellite broadcast ephemeris for Galileo
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GAL            0x008D
typedef struct {
  sbp_ephemeris_common_content_t common;
  float bgd_e1e5a;
  float bgd_e1e5b;
  float c_rs;
  float c_rc;
  float c_uc;
  float c_us;
  float c_ic;
  float c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  float af2;
  sbp_gps_time_sec_t toc;
  u16 iode;
  u16 iodc;
  u8 source;
} sbp_msg_ephemeris_gal_t;



#define SBP_MSG_EPHEMERIS_SBAS_DEP_A     0x0082
typedef struct {
  sbp_ephemeris_common_content_dep_a_t common;
  double pos[3];
  double vel[3];
  double acc[3];
  double a_gf0;
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_a_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A      0x0083
typedef struct {
  sbp_ephemeris_common_content_dep_a_t common;
  double gamma;
  double tau;
  double pos[3];
  double vel[3];
  double acc[3];
} sbp_msg_ephemeris_glo_dep_a_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B     0x0084
typedef struct {
  sbp_ephemeris_common_content_dep_b_t common;
  double pos[3];
  double vel[3];
  double acc[3];
  double a_gf0;
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_b_t;



#define SBP_MSG_EPHEMERIS_SBAS           0x008C
typedef struct {
  sbp_ephemeris_common_content_t common;
  double pos[3];
  float vel[3];
  float acc[3];
  float a_gf0;
  float a_gf1;
} sbp_msg_ephemeris_sbas_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B      0x0085
typedef struct {
  sbp_ephemeris_common_content_dep_b_t common;
  double gamma;
  double tau;
  double pos[3];
  double vel[3];
  double acc[3];
} sbp_msg_ephemeris_glo_dep_b_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C      0x0087
typedef struct {
  sbp_ephemeris_common_content_dep_b_t common;
  double gamma;
  double tau;
  double d_tau;
  double pos[3];
  double vel[3];
  double acc[3];
  u8 fcn;
} sbp_msg_ephemeris_glo_dep_c_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D      0x0088
typedef struct {
  sbp_ephemeris_common_content_dep_b_t common;
  double gamma;
  double tau;
  double d_tau;
  double pos[3];
  double vel[3];
  double acc[3];
  u8 fcn;
  u8 iod;
} sbp_msg_ephemeris_glo_dep_d_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_GLO            0x008B
typedef struct {
  sbp_ephemeris_common_content_t common;
  float gamma;
  float tau;
  float d_tau;
  double pos[3];
  double vel[3];
  float acc[3];
  u8 fcn;
  u8 iod;
} sbp_msg_ephemeris_glo_t;



/** Satellite broadcast ephemeris
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_DEP_D          0x0080
typedef struct {
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  double toe_tow;
  u16 toe_wn;
  double toc_tow;
  u16 toc_wn;
  u8 valid;
  u8 healthy;
  sbp_gnss_signal_dep_t sid;
  u8 iode;
  u16 iodc;
  u32 reserved;
} sbp_msg_ephemeris_dep_d_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_DEP_A          0x001A
typedef struct {
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  double toe_tow;
  u16 toe_wn;
  double toc_tow;
  u16 toc_wn;
  u8 valid;
  u8 healthy;
  u8 prn;
} sbp_msg_ephemeris_dep_a_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_DEP_B          0x0046
typedef struct {
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  double toe_tow;
  u16 toe_wn;
  double toc_tow;
  u16 toc_wn;
  u8 valid;
  u8 healthy;
  u8 prn;
  u8 iode;
} sbp_msg_ephemeris_dep_b_t;



/** Satellite broadcast ephemeris
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EPHEMERIS_DEP_C          0x0047
typedef struct {
  double tgd;
  double c_rs;
  double c_rc;
  double c_uc;
  double c_us;
  double c_ic;
  double c_is;
  double dn;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double inc_dot;
  double af0;
  double af1;
  double af2;
  double toe_tow;
  u16 toe_wn;
  double toc_tow;
  u16 toc_wn;
  u8 valid;
  u8 healthy;
  sbp_gnss_signal_dep_t sid;
  u8 iode;
  u16 iodc;
  u32 reserved;
} sbp_msg_ephemeris_dep_c_t;



/** Header for observation message.
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_gps_time_dep_t t;
  u8 n_obs;
} sbp_observation_header_dep_t;



/** GPS carrier phase measurement.
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 i;
  u8 f;
} sbp_carrier_phase_dep_a_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 P;
  sbp_carrier_phase_dep_a_t L;
  u8 cn0;
  u16 lock;
  u8 prn;
} sbp_packed_obs_content_dep_a_t;



/** GPS observations for a particular satellite signal.
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 P;
  sbp_carrier_phase_dep_a_t L;
  u8 cn0;
  u16 lock;
  sbp_gnss_signal_dep_t sid;
} sbp_packed_obs_content_dep_b_t;



/** GPS observations for a particular satellite signal.
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 P;
  sbp_carrier_phase_t L;
  u8 cn0;
  u16 lock;
  sbp_gnss_signal_dep_t sid;
} sbp_packed_obs_content_dep_c_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_OBS_DEP_A                0x0045
typedef struct {
  sbp_observation_header_dep_t header;
  sbp_packed_obs_content_dep_a_t obs[19];
  u8 n_obs;
} sbp_msg_obs_dep_a_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_OBS_DEP_B                0x0043
typedef struct {
  sbp_observation_header_dep_t header;
  sbp_packed_obs_content_dep_b_t obs[15];
  u8 n_obs;
} sbp_msg_obs_dep_b_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_OBS_DEP_C                0x0049
typedef struct {
  sbp_observation_header_dep_t header;
  sbp_packed_obs_content_dep_c_t obs[15];
  u8 n_obs;
} sbp_msg_obs_dep_c_t;



/** Iono corrections
 *
((m.desc|commentify)))
 */
#define SBP_MSG_IONO                     0x0090
typedef struct {
  sbp_gps_time_sec_t t_nmct;
  double a0;
  double a1;
  double a2;
  double a3;
  double b0;
  double b1;
  double b2;
  double b3;
} sbp_msg_iono_t;



/** L2C capability mask
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SV_CONFIGURATION_GPS_DEP 0x0091
typedef struct {
  sbp_gps_time_sec_t t_nmct;
  u32 l2c_mask;
} sbp_msg_sv_configuration_gps_dep_t;



typedef struct {
  u64 gps_active;
  u64 gps_l2c;
  u64 gps_l5;
  u32 glo_active;
  u32 glo_l2of;
  u32 glo_l3;
  u64 sbas_active;
  u64 sbas_l5;
  u64 bds_active;
  u64 bds_d2nav;
  u64 bds_b2;
  u64 bds_b2a;
  u32 qzss_active;
  u64 gal_active;
  u64 gal_e5;
} sbp_gnss_capb_t;



#define SBP_MSG_GNSS_CAPB                0x0096
typedef struct {
  sbp_gps_time_sec_t t_nmct;
  sbp_gnss_capb_t gc;
} sbp_msg_gnss_capb_t;



/** Group Delay
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GROUP_DELAY_DEP_A        0x0092
typedef struct {
  sbp_gps_time_dep_t t_op;
  u8 prn;
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_dep_a_t;



/** Group Delay
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GROUP_DELAY_DEP_B        0x0093
typedef struct {
  sbp_gps_time_sec_t t_op;
  sbp_gnss_signal_dep_t sid;
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_dep_b_t;



/** Group Delay
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GROUP_DELAY              0x0094
typedef struct {
  sbp_gps_time_sec_t t_op;
  sbp_sbp_gnss_signal_t sid;
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_t;



typedef struct {
  sbp_sbp_gnss_signal_t sid;
  sbp_gps_time_sec_t toa;
  double ura;
  u32 fit_interval;
  u8 valid;
  u8 health_bits;
} sbp_almanac_common_content_t;



typedef struct {
  sbp_gnss_signal_dep_t sid;
  sbp_gps_time_sec_t toa;
  double ura;
  u32 fit_interval;
  u8 valid;
  u8 health_bits;
} sbp_almanac_common_content_dep_t;



/** Satellite broadcast ephemeris for GPS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ALMANAC_GPS_DEP          0x0070
typedef struct {
  sbp_almanac_common_content_dep_t common;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double af0;
  double af1;
} sbp_msg_almanac_gps_dep_t;



/** Satellite broadcast ephemeris for GPS
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ALMANAC_GPS              0x0072
typedef struct {
  sbp_almanac_common_content_t common;
  double m0;
  double ecc;
  double sqrta;
  double omega0;
  double omegadot;
  double w;
  double inc;
  double af0;
  double af1;
} sbp_msg_almanac_gps_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ALMANAC_GLO_DEP          0x0071
typedef struct {
  sbp_almanac_common_content_dep_t common;
  double lambda_na;
  double t_lambda_na;
  double i;
  double t;
  double t_dot;
  double epsilon;
  double omega;
} sbp_msg_almanac_glo_dep_t;



/** Satellite broadcast ephemeris for GLO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ALMANAC_GLO              0x0073
typedef struct {
  sbp_almanac_common_content_t common;
  double lambda_na;
  double t_lambda_na;
  double i;
  double t;
  double t_dot;
  double epsilon;
  double omega;
} sbp_msg_almanac_glo_t;



/** GLONASS L1/L2 Code-Phase biases
 *
((m.desc|commentify)))
 */
#define SBP_MSG_GLO_BIASES               0x0075
typedef struct {
  u8 mask;
  s16 l1ca_bias;
  s16 l1p_bias;
  s16 l2ca_bias;
  s16 l2p_bias;
} sbp_msg_glo_biases_t;



/** Satellite azimuth and elevation.
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u8 az;
  s8 el;
} sbp_sv_az_el_t;



/** Satellite azimuths and elevations
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SV_AZ_EL                 0x0097
typedef struct {
  sbp_sv_az_el_t azel[63];
  u8 n_azel;
} sbp_msg_sv_az_el_t;



/** OSR corrections
 *
((m.desc|commentify)))
 */
#define SBP_MSG_OSR                      0x0640
typedef struct {
  sbp_observation_header_t header;
  sbp_packed_osr_content_t obs[12];
  u8 n_obs;
} sbp_msg_osr_t;




#include <libsbp/unpacked/observation_operators.h>
#include <libsbp/unpacked/observation_packers.h>

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */