#pragma once
#include "Engine.PlayerController.EInputTypes.h"
#include "Engine.PlayerController.EInputMatchAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PlayerController__InputEntry
	{
	public:
		ADD_STRUCT(PlayerController__EInputTypes, Type, 0)
		ADD_STRUCT(float, Value, 4)
		ADD_STRUCT(float, TimeDelta, 8)
		ADD_STRUCT(PlayerController__EInputMatchAction, Action, 12)
	};
}
#undef ADD_STRUCT
