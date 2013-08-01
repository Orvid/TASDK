#pragma once
namespace UnrealScript
{
	enum MeshBeacon__EMeshBeaconBandwidthTestResult : byte
	{
		MB_BandwidthTestResult_Succeeded = 0,
		MB_BandwidthTestResult_Timeout = 1,
		MB_BandwidthTestResult_Error = 2,
		MB_BandwidthTestResult_MAX = 3,
	};
}
