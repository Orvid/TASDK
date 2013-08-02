#pragma once
namespace UnrealScript
{
	class ParticleModuleTrailSpawn;
}
#include "Engine.ParticleModuleTrailBase.h"
#include "Engine.ParticleModuleTrailSpawn.ETrail2SpawnMethod.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailSpawn : public ParticleModuleTrailBase
	{
	public:
		typedef ParticleModuleTrailSpawn__ETrail2SpawnMethod ETrail2SpawnMethod;
		ADD_STRUCT(float, MinSpawnVelocity, 76)
	};
}
#undef ADD_STRUCT
