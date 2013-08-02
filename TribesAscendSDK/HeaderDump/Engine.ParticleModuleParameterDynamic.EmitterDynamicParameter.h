#pragma once
namespace UnrealScript
{
	struct ParticleModuleParameterDynamic__EmitterDynamicParameter;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleParameterDynamic.EEmitterDynamicParameterValue.h"
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
	struct ParticleModuleParameterDynamic__EmitterDynamicParameter
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, ParamValue, 20)
		ADD_BOOL(bScaleVelocityByParamValue, 16, 0x1)
		ADD_STRUCT(ParticleModuleParameterDynamic__EEmitterDynamicParameterValue, ValueMethod, 12)
		ADD_BOOL(bSpawnTimeOnly, 8, 0x2)
		ADD_BOOL(bUseEmitterTime, 8, 0x1)
		ADD_STRUCT(ScriptName, ParamName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
