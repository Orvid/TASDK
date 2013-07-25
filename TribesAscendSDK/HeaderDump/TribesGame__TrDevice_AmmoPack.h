#pragma once
#include "TribesGame__TrDevice_Pack.h"
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_AmmoPack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_AmmoPack : public TrDevice_Pack
	{
	public:
		ADD_VAR(::IntProperty, m_nAmmoPackMultBelt, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAmmoPackMultSecondary, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAmmoPackMultPrimary, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AddAmmoBuff'
		// Here lies the not-yet-implemented method 'ApplyAmmoBuff'
	};
}
#undef ADD_VAR
