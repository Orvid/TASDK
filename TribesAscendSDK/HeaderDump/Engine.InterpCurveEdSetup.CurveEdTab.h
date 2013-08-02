#pragma once
namespace UnrealScript
{
	struct InterpCurveEdSetup__CurveEdTab;
}
#include "Engine.InterpCurveEdSetup.CurveEdEntry.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpCurveEdSetup__CurveEdTab
	{
	public:
		ADD_STRUCT(ScriptArray<InterpCurveEdSetup__CurveEdEntry>, Curves, 12)
		ADD_STRUCT(float, ViewEndOutput, 36)
		ADD_STRUCT(float, ViewStartOutput, 32)
		ADD_STRUCT(float, ViewEndInput, 28)
		ADD_STRUCT(float, ViewStartInput, 24)
		ADD_STRUCT(ScriptString*, TabName, 0)
	};
}
#undef ADD_STRUCT
