#pragma once
namespace UnrealScript
{
	class MaterialExpressionFresnel;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionFresnel : public MaterialExpression
	{
	public:
		ADD_STRUCT(MaterialExpression__ExpressionInput, Normal, 112)
		ADD_STRUCT(float, Exponent, 108)
	};
}
#undef ADD_STRUCT
