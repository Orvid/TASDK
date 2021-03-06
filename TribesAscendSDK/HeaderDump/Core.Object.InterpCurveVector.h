#pragma once
namespace UnrealScript
{
	struct Object__InterpCurveVector;
}
#include "Core.Object.EInterpMethodType.h"
#include "Core.Object.InterpCurvePointVector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InterpCurveVector
	{
	public:
		ADD_STRUCT(ScriptArray<Object__InterpCurvePointVector>, Points, 0)
		ADD_STRUCT(Object__EInterpMethodType, InterpMethod, 12)
	};
}
#undef ADD_STRUCT
