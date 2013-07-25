#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_CastToFloat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_CastToFloat : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::FloatProperty, FloatResult, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Value, 0xFFFFFFFF)
	};
}
#undef ADD_VAR