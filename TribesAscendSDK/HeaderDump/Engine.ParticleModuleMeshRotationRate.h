#pragma once
namespace UnrealScript
{
	class ParticleModuleMeshRotationRate;
}
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleRotationRateBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMeshRotationRate : public ParticleModuleRotationRateBase
	{
	public:
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartRotationRate, 72)
	};
}
#undef ADD_STRUCT
