#pragma once
namespace UnrealScript
{
	class TrConduitVolume;
}
#include "Engine.Pawn.h"
#include "TribesGame.TrPhysicsVolume.h"
namespace UnrealScript
{
	class TrConduitVolume : public TrPhysicsVolume
	{
	public:
		void PawnEnteredVolume(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74627);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74631);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
