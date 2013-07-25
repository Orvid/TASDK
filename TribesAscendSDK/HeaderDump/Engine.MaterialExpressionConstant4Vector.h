#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionConstant4Vector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionConstant4Vector : public MaterialExpression
	{
	public:
		ADD_VAR(::FloatProperty, A, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, B, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, G, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, R, 0xFFFFFFFF)
	};
}
#undef ADD_VAR