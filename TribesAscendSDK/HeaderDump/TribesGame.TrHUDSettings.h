#pragma once
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrHUDSettings.EHUDSettingType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDSettings : public GFxObject
	{
	public:
		ADD_STRUCT(int, SettingsCount, 120)
		ADD_OBJECT(GFxObject, SettingsList, 124)
		float GetCurrentValue(TrHUDSettings__EHUDSettingType Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59226);
			byte params[5] = { NULL };
			*(TrHUDSettings__EHUDSettingType*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void SaveSetting(int Index, float val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96612);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(float*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
