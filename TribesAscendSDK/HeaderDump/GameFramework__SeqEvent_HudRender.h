#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_HudRender." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_HudRender : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
