#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpressionCustom.CustomInput.h"
#include "Engine.MaterialExpressionCustom.ECustomMaterialOutputType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionCustom : public MaterialExpression
	{
	public:
		ADD_STRUCT(ScriptArray<MaterialExpressionCustom__CustomInput>, Inputs, 136)
		ADD_STRUCT(ScriptString*, Description, 124)
		ADD_STRUCT(MaterialExpressionCustom__ECustomMaterialOutputType, OutputType, 120)
		ADD_STRUCT(ScriptString*, Code, 108)
	};
}
#undef ADD_STRUCT
