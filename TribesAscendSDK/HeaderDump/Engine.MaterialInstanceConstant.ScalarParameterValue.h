#pragma once
#include "Core.Object.Guid.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MaterialInstanceConstant__ScalarParameterValue
	{
	public:
		ADD_STRUCT(Object__Guid, ExpressionGUID, 12)
		ADD_STRUCT(float, ParameterValue, 8)
		ADD_STRUCT(ScriptName, ParameterName, 0)
	};
}
#undef ADD_STRUCT
