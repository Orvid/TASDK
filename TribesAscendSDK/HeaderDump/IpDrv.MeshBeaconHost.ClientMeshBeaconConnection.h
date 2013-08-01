#pragma once
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.ENATType.h"
#include "IpDrv.MeshBeaconHost.ClientConnectionBandwidthTestData.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MeshBeaconHost__ClientMeshBeaconConnection
	{
	public:
		ADD_STRUCT(ScriptArray<MeshBeacon__ConnectionBandwidthStats>, BandwidthHistory, 72)
		ADD_STRUCT(int, MinutesSinceLastTest, 84)
		ADD_STRUCT(float, GoodHostRatio, 68)
		ADD_BOOL(bCanHostVs, 64, 0x1)
		ADD_STRUCT(OnlineSubsystem__ENATType, NatType, 60)
		ADD_STRUCT(MeshBeaconHost__ClientConnectionBandwidthTestData, BandwidthTest, 20)
		ADD_BOOL(bConnectionAccepted, 16, 0x1)
		ADD_STRUCT(Object__Pointer, Socket, 12)
		ADD_STRUCT(float, ElapsedHeartbeatTime, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PlayerNetId, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
