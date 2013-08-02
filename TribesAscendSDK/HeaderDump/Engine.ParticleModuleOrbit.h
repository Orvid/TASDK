#pragma once
namespace UnrealScript
{
	class ParticleModuleOrbit;
}
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleOrbit.EOrbitChainMode.h"
#include "Engine.ParticleModuleOrbit.OrbitOptions.h"
#include "Engine.ParticleModuleOrbitBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrbit : public ParticleModuleOrbitBase
	{
	public:
		typedef ParticleModuleOrbit__EOrbitChainMode EOrbitChainMode;
		typedef ParticleModuleOrbit__OrbitOptions OrbitOptions;
		ADD_STRUCT(ParticleModuleOrbit__OrbitOptions, RotationRateOptions, 172)
		ADD_STRUCT(DistributionVector__RawDistributionVector, RotationRateAmount, 144)
		ADD_STRUCT(ParticleModuleOrbit__OrbitOptions, RotationOptions, 140)
		ADD_STRUCT(DistributionVector__RawDistributionVector, RotationAmount, 112)
		ADD_STRUCT(ParticleModuleOrbit__OrbitOptions, OffsetOptions, 108)
		ADD_STRUCT(DistributionVector__RawDistributionVector, OffsetAmount, 80)
		ADD_STRUCT(ParticleModuleOrbit__EOrbitChainMode, ChainMode, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
