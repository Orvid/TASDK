#pragma once
namespace UnrealScript
{
	class ParticleEmitter;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.ParticleEmitter.EEmitterRenderMode.h"
#include "Engine.ParticleEmitter.EParticleBurstMethod.h"
#include "Engine.ParticleEmitter.EParticleSubUVInterpMethod.h"
#include "Engine.ParticleEmitter.ParticleBurst.h"
#include "Engine.ParticleLODLevel.h"
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
	class ParticleEmitter : public Object
	{
	public:
		typedef ParticleEmitter__EEmitterRenderMode EEmitterRenderMode;
		typedef ParticleEmitter__EParticleSubUVInterpMethod EParticleSubUVInterpMethod;
		typedef ParticleEmitter__EParticleBurstMethod EParticleBurstMethod;
		typedef ParticleEmitter__ParticleBurst ParticleBurst;
		ADD_STRUCT(ScriptArray<class ParticleLODLevel*>, LODLevels, 80)
		ADD_STRUCT(int, InitialAllocationCount, 100)
		ADD_STRUCT(int, PeakActiveParticles, 96)
		ADD_BOOL(bCookedOut, 92, 0x8)
		ADD_BOOL(bIsSoloing, 92, 0x4)
		ADD_BOOL(bCollapsed, 92, 0x2)
		ADD_BOOL(ConvertedModules, 92, 0x1)
		ADD_STRUCT(Object__Color, EmitterEditorColor, 76)
		ADD_STRUCT(ParticleEmitter__EEmitterRenderMode, EmitterRenderMode, 72)
		ADD_STRUCT(int, SubUVDataOffset, 68)
		ADD_STRUCT(ScriptName, EmitterName, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
