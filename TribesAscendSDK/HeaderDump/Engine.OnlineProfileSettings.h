#pragma once
#include "Engine.OnlinePlayerStorage.OnlineProfileSetting.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.Settings.IdToStringMapping.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineProfileSettings : public OnlinePlayerStorage
	{
	public:
		ADD_STRUCT(ScriptArray<int>, ProfileSettingIds, 100)
		ADD_STRUCT(ScriptArray<OnlinePlayerStorage__OnlineProfileSetting>, DefaultSettings, 112)
		ADD_STRUCT(ScriptArray<Settings__IdToStringMapping>, OwnerMappings, 124)
		bool GetProfileSettingDefaultId(int ProfileSettingId, int& DefaultId, int& ListIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22645);
			byte params[16] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = DefaultId;
			*(int*)&params[8] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultId = *(int*)&params[4];
			ListIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingDefaultInt(int ProfileSettingId, int& DefaultInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22650);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = DefaultInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultInt = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingDefaultFloat(int ProfileSettingId, float& DefaultFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22654);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(float*)&params[4] = DefaultFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultFloat = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void SetToDefaults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22658);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AppendVersionToReadIds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22659);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyAvailableProfileSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
