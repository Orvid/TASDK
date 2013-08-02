#pragma once
namespace UnrealScript
{
	struct Object__Matrix;
}
#include "Core.Object.Plane.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Matrix
	{
	public:
		ADD_STRUCT(Object__Plane, XPlane, 0)
		ADD_STRUCT(Object__Plane, YPlane, 16)
		ADD_STRUCT(Object__Plane, ZPlane, 32)
		ADD_STRUCT(Object__Plane, WPlane, 48)
	};
}
#undef ADD_STRUCT
