#pragma once
namespace UnrealScript
{
	class TrEffect_DamageBuff;
}
#include "Engine.Actor.h"
#include "Engine.Actor.ImpactInfo.h"
#include "TribesGame.TrEffect_Managed.h"
namespace UnrealScript
{
	class TrEffect_DamageBuff : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, Actor__ImpactInfo Impact)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87112);
			byte params[84] = { NULL };
			*(class Actor**)params = Target;
			*(Actor__ImpactInfo*)&params[4] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87117);
			byte params[4] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
