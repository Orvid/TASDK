#pragma once
namespace UnrealScript
{
	class UDKProfileSettings;
}
#include "Engine.LocalPlayer.h"
#include "Engine.OnlineProfileSettings.h"
namespace UnrealScript
{
	class UDKProfileSettings : public OnlineProfileSettings
	{
	public:
		void ResetToDefault(int ProfileId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35286);
			byte params[4] = { NULL };
			*(int*)params = ProfileId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetKeysToDefault(class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35288);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
