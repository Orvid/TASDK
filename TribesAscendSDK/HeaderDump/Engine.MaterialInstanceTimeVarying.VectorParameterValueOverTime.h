#pragma once
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__VectorParameterValueOverTime;
}
#include "Core.Object.InterpCurveVector.h"
#include "Core.Object.LinearColor.h"
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__VectorParameterValueOverTime : public MaterialInstanceTimeVarying__ParameterValueOverTime
	{
	public:
		ADD_STRUCT(Object__InterpCurveVector, ParameterValueCurve, 64)
		ADD_STRUCT(Object__LinearColor, ParameterValue, 48)
	};
}
#undef ADD_STRUCT
