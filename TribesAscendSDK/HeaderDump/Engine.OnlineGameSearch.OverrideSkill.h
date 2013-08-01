#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Core.Object.Double.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameSearch__OverrideSkill
	{
	public:
		ADD_STRUCT(int, LeaderboardId, 0)
		ADD_STRUCT(ScriptArray<OnlineSubsystem__UniqueNetId>, Players, 4)
		ADD_STRUCT(ScriptArray<Object__Double>, Mus, 16)
		ADD_STRUCT(ScriptArray<Object__Double>, Sigmas, 28)
	};
}
#undef ADD_STRUCT
