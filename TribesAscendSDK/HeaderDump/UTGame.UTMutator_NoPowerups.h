#pragma once
namespace UnrealScript
{
	class UTMutator_NoPowerups;
}
#include "Engine.Actor.h"
#include "UTGame.UTMutator.h"
namespace UnrealScript
{
	class UTMutator_NoPowerups : public UTMutator
	{
	public:
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48604);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
