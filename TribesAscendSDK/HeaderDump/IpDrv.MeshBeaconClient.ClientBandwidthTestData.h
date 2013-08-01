#pragma once
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestState.h"
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MeshBeaconClient__ClientBandwidthTestData
	{
	public:
		ADD_STRUCT(float, ElapsedTestTime, 16)
		ADD_STRUCT(int, NumBytesSentLast, 12)
		ADD_STRUCT(int, NumBytesSentTotal, 8)
		ADD_STRUCT(int, NumBytesToSendTotal, 4)
		ADD_STRUCT(MeshBeacon__EMeshBeaconBandwidthTestState, CurrentState, 1)
		ADD_STRUCT(MeshBeacon__EMeshBeaconBandwidthTestType, TestType, 0)
	};
}
#undef ADD_STRUCT
