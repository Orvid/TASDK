#pragma once
namespace UnrealScript
{
	struct Object__InterpCurvePointQuat;
}
#include "Core.Object.EInterpCurveMode.h"
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointQuat
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(Object__Quat, OutVal, 16)
		ADD_STRUCT(Object__Quat, ArriveTangent, 32)
		ADD_STRUCT(Object__Quat, LeaveTangent, 48)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 64)
	};
}
#undef ADD_STRUCT
