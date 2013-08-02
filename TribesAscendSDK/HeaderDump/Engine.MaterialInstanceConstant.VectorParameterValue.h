#pragma once
namespace UnrealScript
{
	struct MaterialInstanceConstant__VectorParameterValue;
}
#include "Core.Object.Guid.h"
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MaterialInstanceConstant__VectorParameterValue
	{
	public:
		ADD_STRUCT(Object__Guid, ExpressionGUID, 24)
		ADD_STRUCT(Object__LinearColor, ParameterValue, 8)
		ADD_STRUCT(ScriptName, ParameterName, 0)
	};
}
#undef ADD_STRUCT
