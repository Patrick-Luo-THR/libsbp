/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated by generate.py. Do not modify by hand!

#ifndef CHECK_SUITES_H
#define CHECK_SUITES_H

Suite* edc_suite(void);
Suite* sbp_suite(void);
Suite* bitfield_macros_suite(void);
Suite* legacy_auto_check_sbp_acquisition_MsgAcqResultDepA_suite(void);
Suite* legacy_auto_check_sbp_acquisition_MsgAcqResultDepB_suite(void);
Suite* legacy_auto_check_sbp_acquisition_MsgAcqResultDepC_suite(void);
Suite* legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp_suite(void);
Suite* legacy_auto_check_sbp_ext_events_MsgExtEvent_suite(void);
Suite* legacy_auto_check_sbp_file_io_MsgFileioWriteResp_suite(void);
Suite* legacy_auto_check_sbp_imu_MsgImuAux_suite(void);
Suite* legacy_auto_check_sbp_imu_MsgImuRaw_suite(void);
Suite* legacy_auto_check_sbp_logging_MsgFwd_suite(void);
Suite* legacy_auto_check_sbp_logging_MsgLog_suite(void);
Suite* legacy_auto_check_sbp_logging_MsgPrintDep_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgAgeCorrections_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgBaselineECEF_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgBaselineNED_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgBaselineNEDDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgDops_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgDopsDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgGPSTime_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgGPSTimeDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgGPSTimeGNSS_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosECEF_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosECEFCov_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosECEFCovGNSS_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosECEFDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosECEFGNSS_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosLLH_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosLLHCov_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosLLHDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgPosLlhGnss_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgProtectionLevel_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgUTCTime_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgUTCTimeGNSS_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelBody_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelECEF_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelECEFCov_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelECEFDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelEcefCovGnss_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelEcefGnss_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelNED_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelNEDCOV_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelNEDDepA_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelNedCovGnss_suite(void);
Suite* legacy_auto_check_sbp_navigation_MsgVelNedGnss_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgBasePosEcef_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgEphemerisBds_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgEphemerisGLO_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgEphemerisGPS_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgEphemerisGal_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgGloBiases_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgObs_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgObsDepB_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgObsDepC_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgOsr_suite(void);
Suite* legacy_auto_check_sbp_observation_MsgSvAzEl_suite(void);
Suite* legacy_auto_check_sbp_observation_msgEphemerisDepB_suite(void);
Suite* legacy_auto_check_sbp_observation_msgEphemerisQzss_suite(void);
Suite* legacy_auto_check_sbp_observation_msgObsDepA_suite(void);
Suite* legacy_auto_check_sbp_orientation_MsgAngularRate_suite(void);
Suite* legacy_auto_check_sbp_orientation_MsgOrientEuler_suite(void);
Suite* legacy_auto_check_sbp_orientation_MsgOrientQuat_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgDeviceMonitor_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgIarState_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgNetworkBandwidthUsage_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgThreadState_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgUartState_suite(void);
Suite* legacy_auto_check_sbp_piksi_MsgUartStateDepA_suite(void);
Suite* legacy_auto_check_sbp_sbas_MsgSbasRaw_suite(void);
Suite* legacy_auto_check_sbp_settings_MsgSettingsReadByIndexDone_suite(void);
Suite* legacy_auto_check_sbp_settings_MsgSettingsReadByIndexResp_suite(void);
Suite* legacy_auto_check_sbp_system_MsgDgnssStatus_suite(void);
Suite* legacy_auto_check_sbp_system_MsgGroupMeta_suite(void);
Suite* legacy_auto_check_sbp_system_MsgHeartbeat_suite(void);
Suite* legacy_auto_check_sbp_system_MsgInsStatus_suite(void);
Suite* legacy_auto_check_sbp_system_MsgInsUpdates_suite(void);
Suite* legacy_auto_check_sbp_system_MsgStartup_suite(void);
Suite* legacy_auto_check_sbp_tracking_MsgMeasurementState_suite(void);
Suite* legacy_auto_check_sbp_tracking_MsgTrackingState_suite(void);
Suite* legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDep_suite(void);
Suite* legacy_auto_check_sbp_tracking_MsgtrackingStateDepA_suite(void);
Suite* legacy_auto_check_sbp_vehicle_MsgOdometry_suite(void);

#endif /* CHECK_SUITES_H */