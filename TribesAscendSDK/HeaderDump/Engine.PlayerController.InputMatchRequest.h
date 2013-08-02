#pragma once
namespace UnrealScript
{
	struct PlayerController__InputMatchRequest;
}
#include "Engine.Actor.h"
#include "Engine.PlayerController.InputEntry.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct PlayerController__InputMatchRequest
	{
	public:
		ADD_STRUCT(ScriptArray<PlayerController__InputEntry>, Inputs, 0)
		ADD_OBJECT(Actor, MatchActor, 12)
		ADD_STRUCT(ScriptName, MatchFuncName, 16)
		ADD_STRUCT(ScriptName, FailedFuncName, 36)
		ADD_STRUCT(ScriptName, RequestName, 44)
		ADD_STRUCT(int, MatchIdx, 52)
		ADD_STRUCT(float, LastMatchTime, 56)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
