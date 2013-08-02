#pragma once
namespace UnrealScript
{
	struct ParticleSystemComponent__ParticleEventCollideData;
}
#include "Engine.ParticleSystemComponent.ParticleEventData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleSystemComponent__ParticleEventCollideData : public ParticleSystemComponent__ParticleEventData
	{
	public:
		ADD_STRUCT(ScriptName, BoneName, 76)
		ADD_STRUCT(int, Item, 72)
		ADD_STRUCT(float, Time, 68)
		ADD_STRUCT(Vector, Normal, 56)
		ADD_STRUCT(float, ParticleTime, 52)
	};
}
#undef ADD_STRUCT
