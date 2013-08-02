#pragma once
namespace UnrealScript
{
	struct ApexDestructibleAsset__NxDestructibleParameters;
}
#include "Core.Object.Box.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleDepthParameters.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleParametersFlag.h"
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
	struct ApexDestructibleAsset__NxDestructibleParameters
	{
	public:
		ADD_STRUCT(ScriptArray<ApexDestructibleAsset__NxDestructibleDepthParameters>, DepthParameters, 116)
		ADD_STRUCT(float, FractureImpulseScale, 112)
		ADD_STRUCT(float, GrbParticleSpacing, 108)
		ADD_STRUCT(float, GrbVolumeLimit, 104)
		ADD_STRUCT(ApexDestructibleAsset__NxDestructibleParametersFlag, Flags, 100)
		ADD_STRUCT(float, MassScaleExponent, 96)
		ADD_STRUCT(float, MaxChunkSpeed, 92)
		ADD_STRUCT(Object__Box, ValidBounds, 64)
		ADD_STRUCT(float, DebrisMaxSeparationMax, 60)
		ADD_STRUCT(float, DebrisMaxSeparationMin, 56)
		ADD_STRUCT(float, DebrisLifetimeMax, 52)
		ADD_STRUCT(float, DebrisLifetimeMin, 48)
		ADD_STRUCT(int, EssentialDepth, 44)
		ADD_STRUCT(int, DebrisDepth, 40)
		ADD_STRUCT(int, SupportDepth, 36)
		ADD_BOOL(bFormExtendedStructures, 32, 0x1)
		ADD_STRUCT(float, DeformationPercentLimit, 28)
		ADD_STRUCT(float, DamageToPercentDeformation, 24)
		ADD_STRUCT(float, MaterialStrength, 20)
		ADD_STRUCT(float, ImpactVelocityThreshold, 16)
		ADD_STRUCT(float, ForceToDamage, 12)
		ADD_STRUCT(float, DamageCap, 8)
		ADD_STRUCT(float, DamageToRadius, 4)
		ADD_STRUCT(float, DamageThreshold, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
