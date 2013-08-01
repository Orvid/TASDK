#pragma once
#include "Engine.GameplayEvents.EGameStatGroups.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__GameStatGroup
	{
	public:
		ADD_STRUCT(int, Level, 4)
		ADD_STRUCT(GameplayEvents__EGameStatGroups, Group, 0)
	};
}
#undef ADD_STRUCT
