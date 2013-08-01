#pragma once
#include "Core.Object.Double.h"
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestType.h"
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestState.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MeshBeaconHost__ClientConnectionBandwidthTestData
	{
	public:
		ADD_STRUCT(MeshBeacon__ConnectionBandwidthStats, BandwidthStats, 28)
		ADD_STRUCT(Object__Double, TestStartTime, 20)
		ADD_STRUCT(Object__Double, RequestTestStartTime, 12)
		ADD_STRUCT(int, BytesReceived, 8)
		ADD_STRUCT(int, BytesTotalNeeded, 4)
		ADD_STRUCT(MeshBeacon__EMeshBeaconBandwidthTestType, TestType, 1)
		ADD_STRUCT(MeshBeacon__EMeshBeaconBandwidthTestState, CurrentState, 0)
	};
}
#undef ADD_STRUCT
