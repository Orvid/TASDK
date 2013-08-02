#pragma once
namespace UnrealScript
{
	struct Console__scrollbackData;
}
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Console__scrollbackData
	{
	public:
		ADD_STRUCT(Object__Color, OverrideColor, 12)
		ADD_STRUCT(ScriptString*, Text, 0)
	};
}
#undef ADD_STRUCT
