#pragma once
namespace UnrealScript
{
	struct ParticleSystemComponent__ParticleEventDeathData;
}
#include "Engine.ParticleSystemComponent.ParticleEventData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleSystemComponent__ParticleEventDeathData : public ParticleSystemComponent__ParticleEventData
	{
	public:
		ADD_STRUCT(float, ParticleTime, 52)
	};
}
#undef ADD_STRUCT
