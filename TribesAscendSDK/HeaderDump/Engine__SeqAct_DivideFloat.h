#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_DivideFloat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_DivideFloat : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::IntProperty, IntResult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FloatResult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ValueB, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ValueA, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
