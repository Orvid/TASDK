#pragma once
namespace UnrealScript
{
	class GFxTrPage_KeybindMovement;
}
#include "TribesGame.GFxTrPage_KeybindAction.h"
namespace UnrealScript
{
	class GFxTrPage_KeybindMovement : public GFxTrPage_KeybindAction
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59292);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
