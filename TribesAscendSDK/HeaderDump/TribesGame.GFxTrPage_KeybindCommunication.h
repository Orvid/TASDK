#pragma once
namespace UnrealScript
{
	class GFxTrPage_KeybindCommunication;
}
#include "TribesGame.GFxTrPage_KeybindAction.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindCommunication : public GFxTrPage_KeybindAction
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59280);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
