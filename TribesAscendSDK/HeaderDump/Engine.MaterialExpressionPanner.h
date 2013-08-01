#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionPanner : public MaterialExpression
	{
	public:
		ADD_STRUCT(float, SpeedY, 168)
		ADD_STRUCT(float, SpeedX, 164)
		ADD_STRUCT(MaterialExpression__ExpressionInput, Time, 136)
		ADD_STRUCT(MaterialExpression__ExpressionInput, Coordinate, 108)
	};
}
#undef ADD_STRUCT
