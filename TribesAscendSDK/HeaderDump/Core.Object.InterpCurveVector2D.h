#pragma once
#include "Core.Object.InterpCurvePointVector2D.h"
#include "Core.Object.EInterpMethodType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurveVector2D
	{
	public:
		ADD_STRUCT(ScriptArray<Object__InterpCurvePointVector2D>, Points, 0)
		ADD_STRUCT(Object__EInterpMethodType, InterpMethod, 12)
	};
}
#undef ADD_STRUCT
