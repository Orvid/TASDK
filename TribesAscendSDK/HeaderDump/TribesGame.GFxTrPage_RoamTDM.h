#pragma once
namespace UnrealScript
{
	class GFxTrPage_RoamTDM;
}
#include "TribesGame.GFxTrAction.h"
#include "TribesGame.GFxTrPage.h"
namespace UnrealScript
{
	class GFxTrPage_RoamTDM : public GFxTrPage
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60495);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinLocalGame(ScriptString* SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60497);
			byte params[12] = { NULL };
			*(ScriptString**)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60499);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
