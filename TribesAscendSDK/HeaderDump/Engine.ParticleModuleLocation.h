#pragma once
namespace UnrealScript
{
	class ParticleModuleLocation;
}
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleLocationBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocation : public ParticleModuleLocationBase
	{
	public:
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartLocation, 72)
	};
}
#undef ADD_STRUCT
