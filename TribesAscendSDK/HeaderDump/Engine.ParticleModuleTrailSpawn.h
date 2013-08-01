#pragma once
#include "Engine.ParticleModuleTrailBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailSpawn : public ParticleModuleTrailBase
	{
	public:
		ADD_STRUCT(float, MinSpawnVelocity, 76)
	};
}
#undef ADD_STRUCT
