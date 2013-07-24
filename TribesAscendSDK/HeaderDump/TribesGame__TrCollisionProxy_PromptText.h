#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy_PromptText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCollisionProxy_PromptText." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCollisionProxy_PromptText : public TrCollisionProxy
	{
	public:
		ADD_VAR(::FloatProperty, m_fPromptTextRemovalTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPromptMessageIndex, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, m_LocalPawn)
		ADD_VAR(::StrProperty, m_LastUpgradeMsg, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastUpgradeLevel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
