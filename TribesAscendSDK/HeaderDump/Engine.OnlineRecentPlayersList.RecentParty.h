#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineRecentPlayersList__RecentParty
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem__UniqueNetId>, PartyMembers, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PartyLeader, 0)
	};
}
#undef ADD_STRUCT
