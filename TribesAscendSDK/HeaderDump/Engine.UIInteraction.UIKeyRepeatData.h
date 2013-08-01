#pragma once
#include "Core.Object.Double.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIInteraction__UIKeyRepeatData
	{
	public:
		ADD_STRUCT(Object__Double, NextRepeatTime, 8)
		ADD_STRUCT(ScriptName, CurrentRepeatKey, 0)
	};
}
#undef ADD_STRUCT
