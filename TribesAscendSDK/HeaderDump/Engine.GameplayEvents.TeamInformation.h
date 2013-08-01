#pragma once
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__TeamInformation
	{
	public:
		ADD_STRUCT(int, MaxSize, 20)
		ADD_STRUCT(Object__Color, TeamColor, 16)
		ADD_STRUCT(ScriptString*, TeamName, 4)
		ADD_STRUCT(int, TeamIndex, 0)
	};
}
#undef ADD_STRUCT
