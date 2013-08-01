#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTVehicle__TimePosition
	{
	public:
		ADD_STRUCT(float, Time, 12)
		ADD_STRUCT(Vector, Position, 0)
	};
}
#undef ADD_STRUCT
