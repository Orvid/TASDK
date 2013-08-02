#pragma once
namespace UnrealScript
{
	struct Canvas__WrappedStringElement;
}
#include "Core.Object.Vector2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Canvas__WrappedStringElement
	{
	public:
		ADD_STRUCT(Object__Vector2D, LineExtent, 12)
		ADD_STRUCT(ScriptString*, Value, 0)
	};
}
#undef ADD_STRUCT
