#pragma once
namespace UnrealScript
{
	class ParticleModuleBeamSource;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleBeamBase.h"
#include "Engine.ParticleModuleBeamBase.Beam2SourceTargetMethod.h"
#include "Engine.ParticleModuleBeamBase.Beam2SourceTargetTangentMethod.h"
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
	class ParticleModuleBeamSource : public ParticleModuleBeamBase
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, SourceStrength, 144)
		ADD_STRUCT(DistributionVector__RawDistributionVector, SourceTangent, 116)
		ADD_STRUCT(DistributionVector__RawDistributionVector, Source, 88)
		ADD_BOOL(bLockSourceStength, 84, 0x8)
		ADD_BOOL(bLockSourceTangent, 84, 0x4)
		ADD_BOOL(bLockSource, 84, 0x2)
		ADD_BOOL(bSourceAbsolute, 84, 0x1)
		ADD_STRUCT(ScriptName, SourceName, 76)
		ADD_STRUCT(ParticleModuleBeamBase__Beam2SourceTargetTangentMethod, SourceTangentMethod, 73)
		ADD_STRUCT(ParticleModuleBeamBase__Beam2SourceTargetMethod, SourceMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
