#pragma once
namespace UnrealScript
{
	class UTMutator_WeaponsRespawn;
}
#include "UTGame.UTMutator.h"
namespace UnrealScript
{
	class UTMutator_WeaponsRespawn : public UTMutator
	{
	public:
		void InitMutator(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48646);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
	};
}
