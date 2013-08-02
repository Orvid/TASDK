#pragma once
namespace UnrealScript
{
	class ParticleModuleUberRainSplashA;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleUberBase.h"
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
	class ParticleModuleUberRainSplashA : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, AlphaOverLife, 228)
		ADD_STRUCT(DistributionVector__RawDistributionVector, ColorOverLife, 200)
		ADD_STRUCT(DistributionVector__RawDistributionVector, LifeMultiplier, 172)
		ADD_BOOL(MultiplyZ, 168, 0x8)
		ADD_BOOL(MultiplyY, 168, 0x4)
		ADD_BOOL(MultiplyX, 168, 0x2)
		ADD_BOOL(bInheritParent, 168, 0x1)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartRotation, 140)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
