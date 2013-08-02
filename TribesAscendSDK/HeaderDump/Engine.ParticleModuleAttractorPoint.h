#pragma once
namespace UnrealScript
{
	class ParticleModuleAttractorPoint;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleAttractorBase.h"
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
	class ParticleModuleAttractorPoint : public ParticleModuleAttractorBase
	{
	public:
		ADD_BOOL(bUseWorldSpacePosition, 156, 0x8)
		ADD_BOOL(bOverrideVelocity, 156, 0x4)
		ADD_BOOL(bAffectBaseVelocity, 156, 0x2)
		ADD_BOOL(StrengthByDistance, 156, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Strength, 128)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Range, 100)
		ADD_STRUCT(DistributionVector__RawDistributionVector, Position, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
