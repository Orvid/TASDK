#pragma once
#include "Engine.ParticleModuleTrailBase.h"
#include "Core.Object.Vector.h"
#include "Engine.ParticleModuleTrailSource.ETrail2SourceMethod.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModule.EParticleSourceSelectionMethod.h"
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
	class ParticleModuleTrailSource : public ParticleModuleTrailBase
	{
	public:
		ADD_STRUCT(ScriptArray<Vector>, SourceOffsetDefaults, 120)
		ADD_STRUCT(int, SourceOffsetCount, 116)
		ADD_BOOL(bInheritRotation, 112, 0x2)
		ADD_BOOL(bLockSourceStength, 112, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, SourceStrength, 84)
		ADD_STRUCT(ScriptName, SourceName, 76)
		ADD_STRUCT(ParticleModule__EParticleSourceSelectionMethod, SelectionMethod, 73)
		ADD_STRUCT(ParticleModuleTrailSource__ETrail2SourceMethod, SourceMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
