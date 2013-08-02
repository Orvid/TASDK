#pragma once
namespace UnrealScript
{
	struct ParticleModuleOrbit__OrbitOptions;
}
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
	struct ParticleModuleOrbit__OrbitOptions
	{
	public:
		ADD_BOOL(bUseEmitterTime, 0, 0x4)
		ADD_BOOL(bProcessDuringUpdate, 0, 0x2)
		ADD_BOOL(bProcessDuringSpawn, 0, 0x1)
	};
}
#undef ADD_BOOL
