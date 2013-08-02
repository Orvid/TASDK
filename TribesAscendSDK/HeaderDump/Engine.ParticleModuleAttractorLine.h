#pragma once
namespace UnrealScript
{
	class ParticleModuleAttractorLine;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleAttractorBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAttractorLine : public ParticleModuleAttractorBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Strength, 124)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Range, 96)
		ADD_STRUCT(Vector, EndPoint1, 84)
		ADD_STRUCT(Vector, EndPoint0, 72)
	};
}
#undef ADD_STRUCT
