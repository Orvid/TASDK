#pragma once
namespace UnrealScript
{
	class ParticleModuleRequired;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleEmitter.EParticleBurstMethod.h"
#include "Engine.ParticleEmitter.EParticleSubUVInterpMethod.h"
#include "Engine.ParticleEmitter.ParticleBurst.h"
#include "Engine.ParticleModule.h"
#include "Engine.ParticleModuleRequired.EEmitterNormalsMode.h"
#include "Engine.ParticleModuleRequired.EParticleSortMode.h"
#include "Engine.ParticleSpriteEmitter.EParticleScreenAlignment.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleRequired : public ParticleModule
	{
	public:
		typedef ParticleModuleRequired__EEmitterNormalsMode EEmitterNormalsMode;
		typedef ParticleModuleRequired__EParticleSortMode EParticleSortMode;
		ADD_STRUCT(ScriptArray<ParticleEmitter__ParticleBurst>, BurstList, 128)
		ADD_STRUCT(Vector, NormalsCylinderDirection, 184)
		ADD_STRUCT(Vector, NormalsSphereCenter, 172)
		ADD_STRUCT(float, DownsampleThresholdScreenFraction, 168)
		ADD_STRUCT(int, MaxDrawCount, 164)
		ADD_STRUCT(int, RandomImageChanges, 160)
		ADD_STRUCT(float, RandomImageTime, 156)
		ADD_STRUCT(int, SubImages_Vertical, 152)
		ADD_STRUCT(int, SubImages_Horizontal, 148)
		ADD_STRUCT(float, EmitterDelayLow, 144)
		ADD_STRUCT(float, EmitterDelay, 140)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, SpawnRate, 100)
		ADD_STRUCT(int, EmitterLoops, 96)
		ADD_STRUCT(float, EmitterDurationLow, 92)
		ADD_STRUCT(float, EmitterDuration, 88)
		ADD_BOOL(bUseMaxDrawCount, 84, 0x800)
		ADD_BOOL(bDirectUV, 84, 0x400)
		ADD_BOOL(bScaleUV, 84, 0x200)
		ADD_BOOL(bDelayFirstLoopOnly, 84, 0x100)
		ADD_BOOL(bEmitterDelayUseRange, 84, 0x80)
		ADD_BOOL(bDurationRecalcEachLoop, 84, 0x40)
		ADD_BOOL(bEmitterDurationUseRange, 84, 0x20)
		ADD_BOOL(bUseLegacyEmitterTime, 84, 0x10)
		ADD_BOOL(bRequiresSorting, 84, 0x8)
		ADD_BOOL(bKillOnCompleted, 84, 0x4)
		ADD_BOOL(bKillOnDeactivate, 84, 0x2)
		ADD_BOOL(bUseLocalSpace, 84, 0x1)
		ADD_STRUCT(ParticleModuleRequired__EEmitterNormalsMode, EmitterNormalsMode, 80)
		ADD_STRUCT(ParticleEmitter__EParticleSubUVInterpMethod, InterpolationMethod, 79)
		ADD_STRUCT(ParticleEmitter__EParticleBurstMethod, ParticleBurstMethod, 78)
		ADD_STRUCT(ParticleModuleRequired__EParticleSortMode, SortMode, 77)
		ADD_OBJECT(MaterialInterface, Material, 72)
		ADD_STRUCT(ParticleSpriteEmitter__EParticleScreenAlignment, ScreenAlignment, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
