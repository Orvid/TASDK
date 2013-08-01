#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNotify_Trails__TrailSocketSamplePoint
	{
	public:
		ADD_STRUCT(Vector, Velocity, 12)
		ADD_STRUCT(Vector, Position, 0)
	};
}
#undef ADD_STRUCT
