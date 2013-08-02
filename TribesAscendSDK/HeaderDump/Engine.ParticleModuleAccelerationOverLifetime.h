#pragma once
namespace UnrealScript
{
	class ParticleModuleAccelerationOverLifetime;
}
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleAccelerationBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAccelerationOverLifetime : public ParticleModuleAccelerationBase
	{
	public:
		ADD_STRUCT(DistributionVector__RawDistributionVector, AccelOverLife, 76)
	};
}
#undef ADD_STRUCT
