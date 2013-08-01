#pragma once
#include "Engine.DistributionFloatConstant.h"
#include "Engine.DistributionFloatParameterBase.DistributionParamMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatParameterBase : public DistributionFloatConstant
	{
	public:
		ADD_STRUCT(DistributionFloatParameterBase__DistributionParamMode, ParamMode, 108)
		ADD_STRUCT(ScriptName, ParameterName, 84)
		ADD_STRUCT(float, MaxOutput, 104)
		ADD_STRUCT(float, MinOutput, 100)
		ADD_STRUCT(float, MaxInput, 96)
		ADD_STRUCT(float, MinInput, 92)
	};
}
#undef ADD_STRUCT
