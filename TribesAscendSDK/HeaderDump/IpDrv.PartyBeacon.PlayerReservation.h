#pragma once
#include "Core.Object.Double.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PartyBeacon__PlayerReservation
	{
	public:
		ADD_STRUCT(float, ElapsedSessionTime, 32)
		ADD_STRUCT(Object__Double, Sigma, 24)
		ADD_STRUCT(Object__Double, Mu, 16)
		ADD_STRUCT(int, XpLevel, 12)
		ADD_STRUCT(int, Skill, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, NetId, 0)
	};
}
#undef ADD_STRUCT
