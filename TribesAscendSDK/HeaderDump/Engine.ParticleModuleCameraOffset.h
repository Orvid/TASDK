#pragma once
namespace UnrealScript
{
	class ParticleModuleCameraOffset;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleCameraBase.h"
#include "Engine.ParticleModuleCameraOffset.EParticleCameraOffsetUpdateMethod.h"
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
	class ParticleModuleCameraOffset : public ParticleModuleCameraBase
	{
	public:
		typedef ParticleModuleCameraOffset__EParticleCameraOffsetUpdateMethod EParticleCameraOffsetUpdateMethod;
		ADD_STRUCT(ParticleModuleCameraOffset__EParticleCameraOffsetUpdateMethod, UpdateMethod, 104)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, CameraOffset, 72)
		ADD_BOOL(bSpawnTimeOnly, 100, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
