#pragma once
namespace UnrealScript
{
	class ParticleModuleEventReceiverKillParticles;
}
#include "Engine.ParticleModuleEventReceiverBase.h"
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
namespace UnrealScript
{
	class ParticleModuleEventReceiverKillParticles : public ParticleModuleEventReceiverBase
	{
	public:
		ADD_BOOL(bStopSpawning, 84, 0x1)
	};
}
#undef ADD_BOOL
