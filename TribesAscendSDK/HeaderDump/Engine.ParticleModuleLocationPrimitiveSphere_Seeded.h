#pragma once
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveSphere_Seeded;
}
#include "Engine.ParticleModule.ParticleRandomSeedInfo.h"
#include "Engine.ParticleModuleLocationPrimitiveSphere.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveSphere_Seeded : public ParticleModuleLocationPrimitiveSphere
	{
	public:
		ADD_STRUCT(ParticleModule__ParticleRandomSeedInfo, RandomSeedInfo, 160)
	};
}
#undef ADD_STRUCT
