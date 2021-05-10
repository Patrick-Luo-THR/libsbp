#ifndef LIBSBP_SYSTEM_MESSAGES_H
#define LIBSBP_SYSTEM_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
/** System start-up message
 *
 * The system start-up message is sent once on system
 * start-up. It notifies the host or other attached devices that
 * the system has started and is now ready to respond to commands
 * or configuration requests.
 */
#define SBP_MSG_STARTUP 0xFF00

#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK (0x1ff)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT (0u)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_GET(flags) \
  (((flags) >> SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT) & SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK)) << (SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT))); \
  } while (0)

#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_POWER_ON (0)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SOFTWARE_RESET (1)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_WATCHDOG_RESET (2)
#define SBP_STARTUP_STARTUP_TYPE__MASK (0x1ff)
#define SBP_STARTUP_STARTUP_TYPE__SHIFT (0u)
#define SBP_STARTUP_STARTUP_TYPE__GET(flags) \
  (((flags) >> SBP_STARTUP_STARTUP_TYPE__SHIFT) & SBP_STARTUP_STARTUP_TYPE__MASK)
#define SBP_STARTUP_STARTUP_TYPE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STARTUP_STARTUP_TYPE__MASK)) << (SBP_STARTUP_STARTUP_TYPE__SHIFT))); \
  } while (0)

#define SBP_STARTUP_STARTUP_TYPE__COLD_START (0)
#define SBP_STARTUP_STARTUP_TYPE__WARM_START (1)
#define SBP_STARTUP_STARTUP_TYPE__HOT_START (2)
typedef struct
{

  /**
   * Cause of startup
   */
  u8 cause;
  /**
   * Startup type
   */
  u8 startup_type;
  /**
   * Reserved
   */
  u16 reserved;
} sbp_msg_startup_t;

#if 0
#endif
/** Status of received corrections
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */
#define SBP_MSG_DGNSS_STATUS 0xFF02

#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK (0xf)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT (0u)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_GET(flags) \
  (((flags) >> SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT) & SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK)) << (SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT))); \
  } while (0)

#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_INVALID (0)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_CODE_DIFFERENCE (1)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_RTK (2)
typedef struct
{

  /**
   * Status flags
   */
  u8 flags;
  /**
   * Latency of observation receipt[deci-seconds]
   */
  u16 latency;
  /**
   * Number of signals from base station
   */
  u8 num_signals;
  /**
   * Corrections source string
   */
  sbp_unterminated_string_t source;
} sbp_msg_dgnss_status_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_dgnss_status_t_source_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 251u
  };
  static inline void sbp_msg_dgnss_status_t_source_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_dgnss_status_t_source_format); }
  static inline uint8_t sbp_msg_dgnss_status_t_source_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_dgnss_status_t_source_format); }
  static inline uint8_t sbp_msg_dgnss_status_t_source_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_dgnss_status_t_source_format, buf, buf_len); }
  static inline uint8_t sbp_msg_dgnss_status_t_source_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_dgnss_status_t_source_format, buf, buf_len); }
  static inline uint8_t sbp_msg_dgnss_status_t_source_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_dgnss_status_t_source_format); }
  static inline const char *sbp_msg_dgnss_status_t_source_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_dgnss_status_t_source_format, 0); }
  static inline bool sbp_msg_dgnss_status_t_source_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_dgnss_status_t_source_format, new_str); }
#endif
/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It also contains status
 * flags that indicate to the host the status of the system and
 * whether it is operating correctly. Currently, the expected
 * heartbeat interval is 1 sec.
 *
 * The system error flag is used to indicate that an error has
 * occurred in the system. To determine the source of the error,
 * the remaining error flags should be inspected.
 */
#define SBP_MSG_HEARTBEAT 0xFFFF

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT (31u)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT) & SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_NO_EXTERNAL_ANTENNA_DETECTED (0)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_EXTERNAL_ANTENNA_IS_PRESENT (1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT (30u)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT) & SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_NO_SHORT_DETECTED (0)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHORT_DETECTED (1)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (16u)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT (2u)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT) & SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK)) << (SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_AN_ERROR_HAS_OCCURRED_IN_THE_SWIFTNAP (1)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT (1u)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT) & SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK)) << (SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_AN_IO_ERROR_HAS_OCCURRED (1)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT (0u)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT) & SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK)) << (SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_AN_ERROR_HAS_OCCURRED (1)
typedef struct
{

  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_heartbeat_t;

#if 0
#endif
/** Sub-system Status report
 *
 * Report the general and specific state of a sub-system.  If the generic
 * state is reported as initializing, the specific state should be ignored.
 */

#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_MASK (0xffff)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_GET(flags) \
  (((flags) >> SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_SHIFT) & SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_MASK)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_MASK)) << (SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_SHIFT))); \
  } while (0)

#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_CAN (4)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_SUBSYSTEMREPORT_COMPONENT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_MASK (0xff)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_SHIFT (0u)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_GET(flags) \
  (((flags) >> SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_SHIFT) & SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_MASK)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_MASK)) << (SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_SHIFT))); \
  } while (0)

#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_OKNOMINAL (0)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_INITIALIZING (1)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_UNKNOWN (2)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_DEGRADED (3)
#define SBP_SUBSYSTEMREPORT_GENERIC_GENERIC_UNUSABLE (4)
typedef struct
{

  /**
   * Identity of reporting subsystem
   */
  u16 component;
  /**
   * Generic form status report
   */
  u8 generic;
  /**
   * Subsystem specific status code
   */
  u8 specific;
} sbp_sub_system_report_t;

#if 0
#endif
/** Status report message
 *
 * The status report is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It contains status
 * reports that indicate to the host the status of each sub-system and
 * whether it is operating correctly.
 *
 * Interpretation of the subsystem specific status code is product
 * dependent, but if the generic status code is initializing, it should
 * be ignored.  Refer to product documentation for details.
 */
#define SBP_MSG_STATUS_REPORT 0xFFFE

#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT) & SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK)) \
                 << (SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_STARLING (0)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_PRECISION_GNSS_MODULE (1)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0x1ff)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT) & SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK)) \
                 << (SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_CAN (4)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK (0xff)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT (0u)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT) & SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK)) << (SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_OKNOMINAL (0)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_INITIALIZING (1)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_UNKNOWN (2)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_DEGRADED (3)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_UNUSABLE (4)
typedef struct
{

  /**
   * Identity of reporting system
   */
  u16 reporting_system;
  /**
   * SBP protocol version
   */
  u16 sbp_version;
  /**
   * Increments on each status report sent
   */
  u32 sequence;
  /**
   * Number of seconds since system start-up
   */
  u32 uptime;
  /**
   * Reported status of individual subsystems
   */
  sbp_sub_system_report_t status[60];
  /**
   * Number of items in status
   */
  u8 status_count;
} sbp_msg_status_report_t;

#if 0

#if 0
#endif
#endif
/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation
 * and initialization of the inertial navigation system.
 */
#define SBP_MSG_INS_STATUS 0xFF03

#define SBP_INS_STATUS_FLAGS_INS_TYPE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT (29u)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT) & SBP_INS_STATUS_FLAGS_INS_TYPE_MASK)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_INS_TYPE_MASK)) << (SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED (0)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_STARLING (1)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT (11u)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT) & SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK)) << (SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_MOTION_STATE_UNKNOWN_OR_INIT (0)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_ARBITRARY_MOTION (1)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_STRAIGHT_MOTION (2)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_STATIONARY (3)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK (0x1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT (10u)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT) & SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK)) << (SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_NOMINAL (0)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_OUT_OF_BOUNDS (1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK (0x3)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT (8u)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT) & SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK)) << (SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_NO_ODOMETRY (0)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_ODOMETRY_RECEIVED_WITHIN_LAST_SECOND (1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_ODOMETRY_NOT_RECEIVED_WITHIN_LAST_SECOND (2)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_MASK (0xf)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT (4u)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT) & SBP_INS_STATUS_FLAGS_INS_ERROR_MASK)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_INS_ERROR_MASK)) << (SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_INS_ERROR_IMU_DATA_ERROR (1)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_INS_LICENSE_ERROR (2)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_IMU_CALIBRATION_DATA_ERROR (3)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK (0x1)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT (3u)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT) & SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK)) << (SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_GNSS_FIX_NO_GNSS_FIX_AVAILABLE (0)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_GNSS_FIX (1)
#define SBP_INS_STATUS_FLAGS_MODE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_MODE_SHIFT (0u)
#define SBP_INS_STATUS_FLAGS_MODE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_MODE_SHIFT) & SBP_INS_STATUS_FLAGS_MODE_MASK)
#define SBP_INS_STATUS_FLAGS_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_MODE_MASK)) << (SBP_INS_STATUS_FLAGS_MODE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_MODE_AWAITING_INITIALIZATION (0)
#define SBP_INS_STATUS_FLAGS_MODE_DYNAMICALLY_ALIGNING (1)
#define SBP_INS_STATUS_FLAGS_MODE_READY (2)
#define SBP_INS_STATUS_FLAGS_MODE_GNSS_OUTAGE_EXCEEDS_MAX_DURATION (3)
#define SBP_INS_STATUS_FLAGS_MODE_FASTSTART_SEEDING (4)
#define SBP_INS_STATUS_FLAGS_MODE_FASTSTART_VALIDATING (5)
#define SBP_INS_STATUS_FLAGS_MODE_VALIDATING_UNSAFE_FAST_START_SEED (6)
typedef struct
{

  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_ins_status_t;

#if 0
#endif
/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products.
 * It is intended to be a low rate message for status purposes.
 */
#define SBP_MSG_CSAC_TELEMETRY 0xFF04

typedef struct
{

  /**
   * Index representing the type of telemetry in use.  It is implemention defined.
   */
  u8 id;
  /**
   * Comma separated list of values as defined by the index
   */
  sbp_unterminated_string_t telemetry;
} sbp_msg_csac_telemetry_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_csac_telemetry_t_telemetry_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 254u
  };
  static inline void sbp_msg_csac_telemetry_t_telemetry_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_csac_telemetry_t_telemetry_format); }
  static inline uint8_t sbp_msg_csac_telemetry_t_telemetry_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_csac_telemetry_t_telemetry_format); }
  static inline uint8_t sbp_msg_csac_telemetry_t_telemetry_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_csac_telemetry_t_telemetry_format, buf, buf_len); }
  static inline uint8_t sbp_msg_csac_telemetry_t_telemetry_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_csac_telemetry_t_telemetry_format, buf, buf_len); }
  static inline uint8_t sbp_msg_csac_telemetry_t_telemetry_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_csac_telemetry_t_telemetry_format); }
  static inline const char *sbp_msg_csac_telemetry_t_telemetry_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_csac_telemetry_t_telemetry_format, 0); }
  static inline bool sbp_msg_csac_telemetry_t_telemetry_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_csac_telemetry_t_telemetry_format, new_str); }
#endif
/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05

typedef struct
{

  /**
   * Index representing the type of telemetry in use.  It is implemention defined.
   */
  u8 id;
  /**
   * Comma separated list of telemetry field values
   */
  sbp_unterminated_string_t telemetry_labels;
} sbp_msg_csac_telemetry_labels_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 254u
  };
  static inline void sbp_msg_csac_telemetry_labels_t_telemetry_labels_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format); }
  static inline uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format); }
  static inline uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format, buf, buf_len); }
  static inline uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format, buf, buf_len); }
  static inline uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format); }
  static inline const char *sbp_msg_csac_telemetry_labels_t_telemetry_labels_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format, 0); }
  static inline bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_csac_telemetry_labels_t_telemetry_labels_format, new_str); }
#endif
/** Inertial Navigation System update status message
 *
 * The INS update status message contains informations about executed and rejected INS updates.
 * This message is expected to be extended in the future as new types of measurements are being added.
 */
#define SBP_MSG_INS_UPDATES 0xFF06

#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * GNSS position update status flags
   */
  u8 gnsspos;
  /**
   * GNSS velocity update status flags
   */
  u8 gnssvel;
  /**
   * Wheelticks update status flags
   */
  u8 wheelticks;
  /**
   * Wheelticks update status flags
   */
  u8 speed;
  /**
   * NHC update status flags
   */
  u8 nhc;
  /**
   * Zero velocity update status flags
   */
  u8 zerovel;
} sbp_msg_ins_updates_t;

#if 0
#endif
/** Offset of the local time with respect to GNSS time
 *
 * The GNSS time offset message contains the information that is needed to translate messages
 * tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
 * producing this message.
 */
#define SBP_MSG_GNSS_TIME_OFFSET 0xFF07

typedef struct
{

  /**
   * Weeks portion of the time offset[weeks]
   */
  s16 weeks;
  /**
   * Milliseconds portion of the time offset[ms]
   */
  s32 milliseconds;
  /**
   * Microseconds portion of the time offset[microseconds]
   */
  s16 microseconds;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gnss_time_offset_t;

#if 0
#endif
/** Solution Group Metadata
 *
 * This leading message lists the time metadata of the Solution Group.
 * It also lists the atomic contents (i.e. types of messages included) of the Solution Group.
 */
#define SBP_MSG_GROUP_META 0xFF0A

#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GET(flags) \
  (((flags) >> SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT) & SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK)) << (SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT))); \
  } while (0)

#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GNSSINS (2)
typedef struct
{

  /**
   * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
   */
  u8 group_id;
  /**
   * Status flags (reserved)
   */
  u8 flags;
  /**
   * Size of list group_msgs
   */
  u8 n_group_msgs;
  /**
   * An inorder list of message types included in the Solution Group,
   * including GROUP_META itself
   */
  u16 group_msgs[126];
} sbp_msg_group_meta_t;

#if 0
#endif

#include <libsbp/unpacked/system_operators.h>
#include <libsbp/unpacked/system_packers.h>

#endif /* LIBSBP_SYSTEM_MESSAGES_H */
