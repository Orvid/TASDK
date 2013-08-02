#pragma once
namespace UnrealScript
{
	struct EngineTypes__RootMotionCurve;
}
#include "Core.Object.InterpCurveVector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct EngineTypes__RootMotionCurve
	{
	public:
		ADD_STRUCT(float, MaxCurveTime, 24)
		ADD_STRUCT(Object__InterpCurveVector, Curve, 8)
		ADD_STRUCT(ScriptName, AnimName, 0)
	};
}
#undef ADD_STRUCT
