#pragma once
namespace UnrealScript
{
	class UTMutator_BigHead;
}
#include "Engine.Pawn.h"
#include "UTGame.UTMutator.h"
namespace UnrealScript
{
	class UTMutator_BigHead : public UTMutator
	{
	public:
		void ModifyPlayer(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48581);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
