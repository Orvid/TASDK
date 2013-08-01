#pragma once
//#include "Core.Object.Vector.h"
#include "Core.Object.EInterpCurveMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurvePointVector
	{
	public:
		ADD_STRUCT(float, InVal, 0)
		ADD_STRUCT(Vector, OutVal, 4)
		ADD_STRUCT(Vector, ArriveTangent, 16)
		ADD_STRUCT(Vector, LeaveTangent, 28)
		ADD_STRUCT(Object__EInterpCurveMode, InterpMode, 40)
	};
}
#undef ADD_STRUCT
