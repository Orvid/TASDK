#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionParticleMacroUV." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionParticleMacroUV : public MaterialExpression
	{
	public:
		ADD_VAR(::BoolProperty, bUseViewSpace, 0x1)
	};
}
#undef ADD_VAR