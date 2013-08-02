#pragma once
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__ScalarParameterValueOverTime;
}
#include "Core.Object.InterpCurveFloat.h"
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__ScalarParameterValueOverTime : public MaterialInstanceTimeVarying__ParameterValueOverTime
	{
	public:
		ADD_STRUCT(Object__InterpCurveFloat, ParameterValueCurve, 52)
		ADD_STRUCT(float, ParameterValue, 48)
	};
}
#undef ADD_STRUCT
