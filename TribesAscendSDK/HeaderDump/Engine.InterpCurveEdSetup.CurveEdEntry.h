#pragma once
#include "Core.Object.Color.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct InterpCurveEdSetup__CurveEdEntry
	{
	public:
		ADD_STRUCT(float, ClampHigh, 40)
		ADD_STRUCT(float, ClampLow, 36)
		ADD_STRUCT(int, bClamp, 32)
		ADD_STRUCT(int, bFloatingPointColorCurve, 28)
		ADD_STRUCT(int, bColorCurve, 24)
		ADD_STRUCT(int, bHideCurve, 20)
		ADD_STRUCT(ScriptString*, CurveName, 8)
		ADD_STRUCT(Object__Color, CurveColor, 4)
		ADD_OBJECT(Object, CurveObject, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
