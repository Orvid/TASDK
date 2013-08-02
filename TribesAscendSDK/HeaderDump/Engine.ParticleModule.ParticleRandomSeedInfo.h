#pragma once
namespace UnrealScript
{
	struct ParticleModule__ParticleRandomSeedInfo;
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleModule__ParticleRandomSeedInfo
	{
	public:
		ADD_STRUCT(ScriptArray<int>, RandomSeeds, 12)
		ADD_BOOL(bResetSeedOnEmitterLooping, 8, 0x4)
		ADD_BOOL(bInstanceSeedIsIndex, 8, 0x2)
		ADD_BOOL(bGetSeedFromInstance, 8, 0x1)
		ADD_STRUCT(ScriptName, ParameterName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
