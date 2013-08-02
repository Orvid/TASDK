#pragma once
namespace UnrealScript
{
	struct AnimNotify_Trails__TrailSamplePoint;
}
#include "Engine.AnimNotify_Trails.TrailSocketSamplePoint.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNotify_Trails__TrailSamplePoint
	{
	public:
		ADD_STRUCT(AnimNotify_Trails__TrailSocketSamplePoint, SecondEdgeSample, 52)
		ADD_STRUCT(AnimNotify_Trails__TrailSocketSamplePoint, ControlPointSample, 28)
		ADD_STRUCT(AnimNotify_Trails__TrailSocketSamplePoint, FirstEdgeSample, 4)
		ADD_STRUCT(float, RelativeTime, 0)
	};
}
#undef ADD_STRUCT
