#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVGSNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVGSNode : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_bDrawHeader, 0x10)
		ADD_VAR(::StrProperty, m_MenuString, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_KeyBind, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIgnoreCaH, 0x8)
		ADD_VAR(::BoolProperty, m_bIgnoreArena, 0x4)
		ADD_VAR(::BoolProperty, m_bIgnoreTeamRabbit, 0x2)
		ADD_VAR(::BoolProperty, m_bIgnoreCTF, 0x1)
	};
}
#undef ADD_VAR
