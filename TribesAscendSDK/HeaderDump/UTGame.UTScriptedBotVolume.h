#pragma once
namespace UnrealScript
{
	class UTScriptedBotVolume;
}
#include "Engine.Pawn.h"
#include "Engine.PhysicsVolume.h"
namespace UnrealScript
{
	class UTScriptedBotVolume : public PhysicsVolume
	{
	public:
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49026);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
