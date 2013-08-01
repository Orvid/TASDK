#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
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
	class ParticleModuleUberLTISIVCLILIRSSBLIRR : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartRotationRate, 340)
		ADD_BOOL(SizeMultiplyZ, 336, 0x4)
		ADD_BOOL(SizeMultiplyY, 336, 0x2)
		ADD_BOOL(SizeMultiplyX, 336, 0x1)
		ADD_STRUCT(DistributionVector__RawDistributionVector, SizeLifeMultiplier, 308)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartRotation, 280)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartLocation, 252)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, AlphaOverLife, 224)
		ADD_STRUCT(DistributionVector__RawDistributionVector, ColorOverLife, 196)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartVelocityRadial, 168)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartVelocity, 140)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
