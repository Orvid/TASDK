#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqCond_IsLoggedIn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqCond_IsLoggedIn : public SequenceCondition
	{
	public:
		ADD_VAR(::IntProperty, NumNeededLoggedIn, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
