#pragma once
namespace UnrealScript
{
	class ParticleModuleParameterDynamic;
}
#include "Engine.ParticleModuleParameterBase.h"
#include "Engine.ParticleModuleParameterDynamic.EEmitterDynamicParameterValue.h"
#include "Engine.ParticleModuleParameterDynamic.EmitterDynamicParameter.h"
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
	class ParticleModuleParameterDynamic : public ParticleModuleParameterBase
	{
	public:
		typedef ParticleModuleParameterDynamic__EEmitterDynamicParameterValue EEmitterDynamicParameterValue;
		typedef ParticleModuleParameterDynamic__EmitterDynamicParameter EmitterDynamicParameter;
		ADD_STRUCT(ScriptArray<ParticleModuleParameterDynamic__EmitterDynamicParameter>, DynamicParams, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
