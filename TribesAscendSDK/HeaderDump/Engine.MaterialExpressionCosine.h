#pragma once
namespace UnrealScript
{
	class MaterialExpressionCosine;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionCosine : public MaterialExpression
	{
	public:
		ADD_STRUCT(float, Period, 136)
		ADD_STRUCT(MaterialExpression__ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
