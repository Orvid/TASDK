#pragma once
namespace UnrealScript
{
	class ParticleModuleCollision;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleCollisionBase.h"
#include "Engine.ParticleModuleCollisionBase.EParticleCollisionComplete.h"
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
	class ParticleModuleCollision : public ParticleModuleCollisionBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, DelayAmount, 200)
		ADD_STRUCT(float, VerticalFudgeFactor, 196)
		ADD_STRUCT(float, DirScalar, 192)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, ParticleMass, 164)
		ADD_BOOL(bDropDetail, 160, 0x8)
		ADD_BOOL(bOnlyVerticalNormalsDecrementCount, 160, 0x4)
		ADD_BOOL(bPawnsDoNotDecrementCount, 160, 0x2)
		ADD_BOOL(bApplyPhysics, 160, 0x1)
		ADD_STRUCT(ParticleModuleCollisionBase__EParticleCollisionComplete, CollisionCompletionOption, 156)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, MaxCollisions, 128)
		ADD_STRUCT(DistributionVector__RawDistributionVector, DampingFactorRotation, 100)
		ADD_STRUCT(DistributionVector__RawDistributionVector, DampingFactor, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
