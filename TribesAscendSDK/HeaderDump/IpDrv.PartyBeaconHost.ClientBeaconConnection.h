#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PartyBeaconHost__ClientBeaconConnection
	{
	public:
		ADD_STRUCT(Object__Pointer, Socket, 12)
		ADD_STRUCT(float, ElapsedHeartbeatTime, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PartyLeader, 0)
	};
}
#undef ADD_STRUCT
