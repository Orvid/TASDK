#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.EInterpCurveMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointVector2D
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(Object__Vector2D, OutVal, 4)
		ADD_STRUCT(Object__Vector2D, ArriveTangent, 12)
		ADD_STRUCT(Object__Vector2D, LeaveTangent, 20)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 28)
	};
}
#undef ADD_STRUCT
