#pragma once
namespace UnrealScript
{
	class ParticleModuleLifetime;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleLifetimeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLifetime : public ParticleModuleLifetimeBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Lifetime, 72)
	};
}
#undef ADD_STRUCT
