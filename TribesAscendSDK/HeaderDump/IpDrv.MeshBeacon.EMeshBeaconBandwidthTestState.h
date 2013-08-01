#pragma once
namespace UnrealScript
{
	enum MeshBeacon__EMeshBeaconBandwidthTestState : byte
	{
		MB_BandwidthTestState_NotStarted = 0,
		MB_BandwidthTestState_RequestPending = 1,
		MB_BandwidthTestState_StartPending = 2,
		MB_BandwidthTestState_InProgress = 3,
		MB_BandwidthTestState_Completed = 4,
		MB_BandwidthTestState_Incomplete = 5,
		MB_BandwidthTestState_Timeout = 6,
		MB_BandwidthTestState_Error = 7,
		MB_BandwidthTestState_MAX = 8,
	};
}
