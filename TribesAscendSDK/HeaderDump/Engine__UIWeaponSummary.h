#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIWeaponSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIWeaponSummary : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bIsDisabled, 0x1)
		ADD_VAR(::StrProperty, WeaponDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassPathName, 0xFFFFFFFF)
		bool IsProviderDisabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIWeaponSummary.IsProviderDisabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
