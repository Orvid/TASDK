#pragma once
namespace UnrealScript
{
	class UTAmbientSoundComponent;
}
#include "Engine.AudioComponent.h"
namespace UnrealScript
{
	class UTAmbientSoundComponent : public AudioComponent
	{
	public:
		void OcclusionChanged(bool bNowOccluded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40389);
			byte params[4] = { NULL };
			*(bool*)params = bNowOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
