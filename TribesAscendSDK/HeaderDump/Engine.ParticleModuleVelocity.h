#pragma once
namespace UnrealScript
{
	class ParticleModuleVelocity;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleVelocityBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocity : public ParticleModuleVelocityBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartVelocityRadial, 104)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartVelocity, 76)
	};
}
#undef ADD_STRUCT
