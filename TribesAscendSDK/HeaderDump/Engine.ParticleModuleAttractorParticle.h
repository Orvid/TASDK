#pragma once
namespace UnrealScript
{
	class ParticleModuleAttractorParticle;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleAttractorBase.h"
#include "Engine.ParticleModuleAttractorParticle.EAttractorParticleSelectionMethod.h"
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
	class ParticleModuleAttractorParticle : public ParticleModuleAttractorBase
	{
	public:
		typedef ParticleModuleAttractorParticle__EAttractorParticleSelectionMethod EAttractorParticleSelectionMethod;
		ADD_STRUCT(int, LastSelIndex, 144)
		ADD_STRUCT(ParticleModuleAttractorParticle__EAttractorParticleSelectionMethod, SelectionMethod, 140)
		ADD_STRUCT(ScriptName, EmitterName, 72)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Strength, 112)
		ADD_BOOL(bInheritSourceVel, 108, 0x8)
		ADD_BOOL(bRenewSource, 108, 0x4)
		ADD_BOOL(bAffectBaseVelocity, 108, 0x2)
		ADD_BOOL(bStrengthByDistance, 108, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Range, 80)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
