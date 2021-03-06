#pragma once
namespace UnrealScript
{
	class MaterialExpressionTransformPosition;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#include "Engine.MaterialExpressionTransformPosition.EMaterialPositionTransform.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTransformPosition : public MaterialExpression
	{
	public:
		typedef MaterialExpressionTransformPosition__EMaterialPositionTransform EMaterialPositionTransform;
		ADD_STRUCT(MaterialExpressionTransformPosition__EMaterialPositionTransform, TransformType, 136)
		ADD_STRUCT(MaterialExpression__ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
