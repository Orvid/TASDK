#pragma once
#include "Engine.ParticleModuleOrientationBase.h"
#include "Engine.ParticleModuleOrientationAxisLock.EParticleAxisLock.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrientationAxisLock : public ParticleModuleOrientationBase
	{
	public:
		ADD_STRUCT(ParticleModuleOrientationAxisLock__EParticleAxisLock, LockAxisFlags, 72)
	};
}
#undef ADD_STRUCT
