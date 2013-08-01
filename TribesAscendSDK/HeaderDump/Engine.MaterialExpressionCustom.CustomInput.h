#pragma once
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MaterialExpressionCustom__CustomInput
	{
	public:
		ADD_STRUCT(MaterialExpression__ExpressionInput, Input, 12)
		ADD_STRUCT(ScriptString*, InputName, 0)
	};
}
#undef ADD_STRUCT
