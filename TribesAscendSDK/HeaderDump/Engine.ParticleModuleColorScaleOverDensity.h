#pragma once
#include "Engine.ParticleModuleColorBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColorScaleOverDensity : public ParticleModuleColorBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, AlphaScaleOverDensity, 100)
		ADD_STRUCT(DistributionVector__RawDistributionVector, ColorScaleOverDensity, 72)
	};
}
#undef ADD_STRUCT
