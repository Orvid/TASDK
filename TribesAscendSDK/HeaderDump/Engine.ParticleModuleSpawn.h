#pragma once
namespace UnrealScript
{
	class ParticleModuleSpawn;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleEmitter.EParticleBurstMethod.h"
#include "Engine.ParticleEmitter.ParticleBurst.h"
#include "Engine.ParticleModuleSpawnBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSpawn : public ParticleModuleSpawnBase
	{
	public:
		ADD_STRUCT(ScriptArray<ParticleEmitter__ParticleBurst>, BurstList, 136)
		ADD_STRUCT(ParticleEmitter__EParticleBurstMethod, ParticleBurstMethod, 132)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, RateScale, 104)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Rate, 76)
	};
}
#undef ADD_STRUCT
