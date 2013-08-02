#pragma once
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCL;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleUberBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCL : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, AlphaOverLife, 224)
		ADD_STRUCT(DistributionVector__RawDistributionVector, ColorOverLife, 196)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartVelocityRadial, 168)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartVelocity, 140)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_STRUCT
