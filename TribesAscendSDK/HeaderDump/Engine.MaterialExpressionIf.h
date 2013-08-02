#pragma once
namespace UnrealScript
{
	class MaterialExpressionIf;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionIf : public MaterialExpression
	{
	public:
		ADD_STRUCT(MaterialExpression__ExpressionInput, ALessThanB, 220)
		ADD_STRUCT(MaterialExpression__ExpressionInput, AEqualsB, 192)
		ADD_STRUCT(MaterialExpression__ExpressionInput, AGreaterThanB, 164)
		ADD_STRUCT(MaterialExpression__ExpressionInput, B, 136)
		ADD_STRUCT(MaterialExpression__ExpressionInput, A, 108)
	};
}
#undef ADD_STRUCT
