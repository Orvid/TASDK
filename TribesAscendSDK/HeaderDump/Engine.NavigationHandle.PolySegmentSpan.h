#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct NavigationHandle__PolySegmentSpan
	{
	public:
		ADD_STRUCT(Vector, P2, 16)
		ADD_STRUCT(Vector, P1, 4)
		ADD_STRUCT(Object__Pointer, Poly, 0)
	};
}
#undef ADD_STRUCT
