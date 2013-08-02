#pragma once
namespace UnrealScript
{
	class DebugCameraInput;
}
#include "Core.Object.EInputEvent.h"
#include "Engine.PlayerInput.h"
namespace UnrealScript
{
	class DebugCameraInput : public PlayerInput
	{
	public:
		bool InputKey(int ControllerId, ScriptName Key, Object__EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14027);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object__EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
