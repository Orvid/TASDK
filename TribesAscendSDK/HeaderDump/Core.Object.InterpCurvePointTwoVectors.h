#pragma once
#include "Core.Object.TwoVectors.h"
#include "Core.Object.EInterpCurveMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointTwoVectors
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(Object__TwoVectors, OutVal, 4)
		ADD_STRUCT(Object__TwoVectors, ArriveTangent, 28)
		ADD_STRUCT(Object__TwoVectors, LeaveTangent, 52)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 76)
	};
}
#undef ADD_STRUCT
