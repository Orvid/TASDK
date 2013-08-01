#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNotify_Trails__TrailSample
	{
	public:
		ADD_STRUCT(Vector, SecondEdgeSample, 28)
		ADD_STRUCT(Vector, ControlPointSample, 16)
		ADD_STRUCT(Vector, FirstEdgeSample, 4)
		ADD_STRUCT(float, RelativeTime, 0)
	};
}
#undef ADD_STRUCT
