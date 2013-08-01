#pragma once
#include "Engine.Emitter.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKPawn.DistanceBasedParticleTemplate.h"
#include "Core.Object.Vector.h"
#include "Engine.WorldInfo.h"
namespace UnrealScript
{
	class UTEmitter : public Emitter
	{
	public:
		class ParticleSystem* GetTemplateForDistance(ScriptArray<UDKPawn__DistanceBasedParticleTemplate>& TemplateList, Vector SpawnLocation, class WorldInfo* WI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40133);
			byte params[32] = { NULL };
			*(ScriptArray<UDKPawn__DistanceBasedParticleTemplate>*)params = TemplateList;
			*(Vector*)&params[12] = SpawnLocation;
			*(class WorldInfo**)&params[24] = WI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TemplateList = *(ScriptArray<UDKPawn__DistanceBasedParticleTemplate>*)params;
			return *(class ParticleSystem**)&params[28];
		}
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47361);
			byte params[8] = { NULL };
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47366);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
