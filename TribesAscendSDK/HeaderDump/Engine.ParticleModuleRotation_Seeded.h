#pragma once
namespace UnrealScript
{
	class ParticleModuleRotation_Seeded;
}
#include "Engine.ParticleModule.ParticleRandomSeedInfo.h"
#include "Engine.ParticleModuleRotation.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotation_Seeded : public ParticleModuleRotation
	{
	public:
		ADD_STRUCT(ParticleModule__ParticleRandomSeedInfo, RandomSeedInfo, 100)
	};
}
#undef ADD_STRUCT
