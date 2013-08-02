#pragma once
namespace UnrealScript
{
	class ParticleModuleTrailTaper;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleTrailBase.h"
#include "Engine.ParticleModuleTrailTaper.ETrailTaperMethod.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailTaper : public ParticleModuleTrailBase
	{
	public:
		typedef ParticleModuleTrailTaper__ETrailTaperMethod ETrailTaperMethod;
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, TaperFactor, 76)
		ADD_STRUCT(ParticleModuleTrailTaper__ETrailTaperMethod, TaperMethod, 72)
	};
}
#undef ADD_STRUCT
