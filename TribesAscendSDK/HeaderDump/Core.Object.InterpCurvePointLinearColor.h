#pragma once
#include "Core.Object.LinearColor.h"
#include "Core.Object.EInterpCurveMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointLinearColor
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(Object__LinearColor, OutVal, 4)
		ADD_STRUCT(Object__LinearColor, ArriveTangent, 20)
		ADD_STRUCT(Object__LinearColor, LeaveTangent, 36)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 52)
	};
}
#undef ADD_STRUCT
