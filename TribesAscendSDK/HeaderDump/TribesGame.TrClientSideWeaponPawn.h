#pragma once
namespace UnrealScript
{
	class TrClientSideWeaponPawn;
}
#include "Engine.Pawn.h"
#include "UTGame.UTClientSideWeaponPawn.h"
namespace UnrealScript
{
	class TrClientSideWeaponPawn : public UTClientSideWeaponPawn
	{
	public:
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74486);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
