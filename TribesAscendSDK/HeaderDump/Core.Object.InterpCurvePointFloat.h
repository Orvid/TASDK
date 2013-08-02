#pragma once
namespace UnrealScript
{
	struct Object__InterpCurvePointFloat;
}
#include "Core.Object.EInterpCurveMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointFloat
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(float, OutVal, 4)
		ADD_STRUCT(float, ArriveTangent, 8)
		ADD_STRUCT(float, LeaveTangent, 12)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 16)
	};
}
#undef ADD_STRUCT
