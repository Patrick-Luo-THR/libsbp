#ifndef LIBSBP_VEHICLE_MESSAGES_H
#define LIBSBP_VEHICLE_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
  /** Vehicle forward (x-axis) velocity
   *
 * Message representing the x component of vehicle velocity in the user frame at the odometry
 * reference point(s) specified by the user. The offset for the odometry reference point and 
 * the definition and origin of the user frame are defined through the device settings interface.
 * There are 4 possible user-defined sources of this message  which are labeled arbitrarily 
 * source 0 through 3.
 * If using "processor time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise odometry measurements
 * with GNSS. Processor time shall roll over to zero after one week.
   */
#define SBP_MSG_ODOMETRY  0x0903

	#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK (0x3)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT (5u)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT) \
                             & SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK)) \
                             << (SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_FORWARD (1)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_REVERSE (2)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_PARK (3)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK (0x3)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT (3u)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT) \
                             & SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK)) \
                             << (SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_0 (0)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_1 (1)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_2 (2)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_3 (3)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT) \
                             & SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK)) \
                             << (SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_GPS_SOLUTION (1)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_PROCESSOR_TIME (2)
typedef struct {
  
  /**
 * Time field representing either milliseconds in the GPS Week or local CPU
 * time from the producing system in milliseconds.  See the tow_source flag
 * for the exact source of this timestamp.[ms]
   */
    u32
  tow
  ;
  /**
 * The signed forward component of vehicle velocity.[mm/s]
   */
    s32
  velocity
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_odometry_t;


  /** Accumulated wheeltick count message
   *
 * Message containing the accumulated distance travelled by a wheel located at an odometry
 * reference point defined by the user. The offset for the odometry reference point and the
 * definition and origin of the user frame are defined through the device settings interface.
 * The source of this message is identified by the source field, which is an integer ranging
 * from 0 to 255.
 * The timestamp associated with this message should represent the time when the accumulated
 * tick count reached the value given by the contents of this message as accurately as possible.
 * If using "local CPU time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise wheeltick measurements
 * with GNSS. Local CPU time shall roll over to zero after one week.
   */
#define SBP_MSG_WHEELTICK 0x0904

	#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK (0x3)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT (2u)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_GET(flags) \
                             (((flags) >> SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT) \
                             & SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK)) \
                             << (SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT)));} while(0)
                             

#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_FORWARD (1)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_REVERSE (2)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_PARK (3)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK (0x3)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT (0u)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_GET(flags) \
                             (((flags) >> SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT) \
                             & SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK)) \
                             << (SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT)));} while(0)
                             

#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MICROSECONDS_SINCE_LAST_PPS (0)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MICROSECONDS_IN_GPS_WEEK (1)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_LOCAL_CPU_TIME_IN_NOMINAL_MICROSECONDS (2)
typedef struct {
  
  /**
 * Time field representing either microseconds since the last PPS, microseconds in the GPS
 * Week or local CPU time from the producing system in microseconds. See the synch_type
 * field for the exact meaning of this timestamp.[us]
   */
    u64
  time
  ;
  /**
 * Field indicating the type of timestamp contained in the time field.
   */
    u8
  flags
  ;
  /**
 * ID of the sensor producing this message
   */
    u8
  source
  ;
  /**
 * Free-running counter of the accumulated distance for this sensor. The counter should be
 * incrementing if travelling into one direction and decrementing when travelling in the
 * opposite direction.[arbitrary distance units]
   */
    s32
  ticks
  ;
} sbp_msg_wheeltick_t;



#include <libsbp/unpacked/vehicle_operators.h>
#include <libsbp/unpacked/vehicle_packers.h>

#endif /* LIBSBP_VEHICLE_MESSAGES_H */
