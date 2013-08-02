#pragma once
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveSphere;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleLocationPrimitiveBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveSphere : public ParticleModuleLocationPrimitiveBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartRadius, 132)
	};
}
#undef ADD_STRUCT
