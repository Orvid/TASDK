#pragma once
namespace UnrealScript
{
	enum MeshBeacon__EMeshBeaconBandwidthTestType : byte
	{
		MB_BandwidthTestType_Upstream = 0,
		MB_BandwidthTestType_Downstream = 1,
		MB_BandwidthTestType_RoundtripLatency = 2,
		MB_BandwidthTestType_MAX = 3,
	};
}
