#pragma once
namespace UnrealScript
{
	class GFxUDKFrontEnd_ServerSettings;
}
#include "GFxUI.GFxClikWidget.EventData.h"
#include "GFxUI.GFxObject.h"
#include "UTGame.GFxUDKFrontEnd_SettingsBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
namespace UnrealScript
{
	class GFxUDKFrontEnd_ServerSettings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		ADD_BOOL(bDataChangedByReqs, 260, 0x1)
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39027);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnOptionChanged(GFxClikWidget__EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39028);
			byte params[36] = { NULL };
			*(GFxClikWidget__EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39043);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateOptionDataProviderForIndex(int Index, class GFxObject*& OutDataProvider, ScriptString*& OutDefaultValue, int& OutDefaultIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39051);
			byte params[24] = { NULL };
			*(int*)params = Index;
			*(class GFxObject**)&params[4] = OutDataProvider;
			*(ScriptString**)&params[8] = OutDefaultValue;
			*(int*)&params[20] = OutDefaultIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDataProvider = *(class GFxObject**)&params[4];
			OutDefaultValue = *(ScriptString**)&params[8];
			OutDefaultIndex = *(int*)&params[20];
		}
		ScriptString* FindControlByUTClassName(byte UTUIControlClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39061);
			byte params[13] = { NULL };
			*params = UTUIControlClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
