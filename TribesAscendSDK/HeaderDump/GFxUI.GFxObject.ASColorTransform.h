#pragma once
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxObject__ASColorTransform
	{
	public:
		ADD_STRUCT(Object__LinearColor, Add, 16)
		ADD_STRUCT(Object__LinearColor, Multiply, 0)
	};
}
#undef ADD_STRUCT
