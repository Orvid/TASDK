#pragma once
namespace UnrealScript
{
	struct PartyBeacon__PartyReservation;
}
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "IpDrv.PartyBeacon.PlayerReservation.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PartyBeacon__PartyReservation
	{
	public:
		ADD_STRUCT(ScriptArray<PartyBeacon__PlayerReservation>, PartyMembers, 12)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PartyLeader, 4)
		ADD_STRUCT(int, TeamNum, 0)
	};
}
#undef ADD_STRUCT
