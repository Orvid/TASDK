#pragma once
namespace UnrealScript
{
	class MaterialExpressionTransform;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#include "Engine.MaterialExpressionTransform.EMaterialVectorCoordTransform.h"
#include "Engine.MaterialExpressionTransform.EMaterialVectorCoordTransformSource.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTransform : public MaterialExpression
	{
	public:
		typedef MaterialExpressionTransform__EMaterialVectorCoordTransform EMaterialVectorCoordTransform;
		typedef MaterialExpressionTransform__EMaterialVectorCoordTransformSource EMaterialVectorCoordTransformSource;
		ADD_STRUCT(MaterialExpressionTransform__EMaterialVectorCoordTransform, TransformType, 137)
		ADD_STRUCT(MaterialExpressionTransform__EMaterialVectorCoordTransformSource, TransformSourceType, 136)
		ADD_STRUCT(MaterialExpression__ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
