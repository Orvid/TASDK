#pragma once
namespace UnrealScript
{
	class TrProj_LightSpinfusor;
}
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_LightSpinfusor : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108598);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
