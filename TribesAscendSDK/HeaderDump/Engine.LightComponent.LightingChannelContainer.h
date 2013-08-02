#pragma once
namespace UnrealScript
{
	struct LightComponent__LightingChannelContainer;
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
	struct LightComponent__LightingChannelContainer
	{
	public:
		ADD_BOOL(Crowd, 0, 0x4000000)
		ADD_BOOL(Gameplay_4, 0, 0x2000000)
		ADD_BOOL(Gameplay_3, 0, 0x1000000)
		ADD_BOOL(Gameplay_2, 0, 0x800000)
		ADD_BOOL(Gameplay_1, 0, 0x400000)
		ADD_BOOL(Cinematic_10, 0, 0x200000)
		ADD_BOOL(Cinematic_9, 0, 0x100000)
		ADD_BOOL(Cinematic_8, 0, 0x80000)
		ADD_BOOL(Cinematic_7, 0, 0x40000)
		ADD_BOOL(Cinematic_6, 0, 0x20000)
		ADD_BOOL(Cinematic_5, 0, 0x10000)
		ADD_BOOL(Cinematic_4, 0, 0x8000)
		ADD_BOOL(Cinematic_3, 0, 0x4000)
		ADD_BOOL(Cinematic_2, 0, 0x2000)
		ADD_BOOL(Cinematic_1, 0, 0x1000)
		ADD_BOOL(Unnamed_6, 0, 0x800)
		ADD_BOOL(Unnamed_5, 0, 0x400)
		ADD_BOOL(Unnamed_4, 0, 0x200)
		ADD_BOOL(Unnamed_3, 0, 0x100)
		ADD_BOOL(Unnamed_2, 0, 0x80)
		ADD_BOOL(Unnamed_1, 0, 0x40)
		ADD_BOOL(Skybox, 0, 0x20)
		ADD_BOOL(CompositeDynamic, 0, 0x10)
		ADD_BOOL(Dynamic, 0, 0x8)
		ADD_BOOL(Static, 0, 0x4)
		ADD_BOOL(BSP, 0, 0x2)
		ADD_BOOL(bInitialized, 0, 0x1)
	};
}
#undef ADD_BOOL
