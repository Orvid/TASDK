#pragma once
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#include "Engine.OnlineSubsystem.ENATType.h"
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
	struct MeshBeaconClient__ClientConnectionRequest
	{
	public:
		ADD_STRUCT(ScriptArray<MeshBeacon__ConnectionBandwidthStats>, BandwidthHistory, 20)
		ADD_STRUCT(int, MinutesSinceLastTest, 32)
		ADD_STRUCT(float, GoodHostRatio, 16)
		ADD_BOOL(bCanHostVs, 12, 0x1)
		ADD_STRUCT(OnlineSubsystem__ENATType, NatType, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PlayerNetId, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
