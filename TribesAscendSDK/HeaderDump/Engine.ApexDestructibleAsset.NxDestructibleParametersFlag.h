#pragma once
namespace UnrealScript
{
	struct ApexDestructibleAsset__NxDestructibleParametersFlag;
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
	struct ApexDestructibleAsset__NxDestructibleParametersFlag
	{
	public:
		ADD_BOOL(USE_VALID_BOUNDS, 0, 0x80)
		ADD_BOOL(ACCURATE_RAYCASTS, 0, 0x40)
		ADD_BOOL(CRUMBLE_SMALLEST_CHUNKS, 0, 0x20)
		ADD_BOOL(DEBRIS_MAX_SEPARATION, 0, 0x10)
		ADD_BOOL(DEBRIS_TIMEOUT, 0, 0x8)
		ADD_BOOL(WORLD_SUPPORT, 0, 0x4)
		ADD_BOOL(ASSET_DEFINED_SUPPORT, 0, 0x2)
		ADD_BOOL(ACCUMULATE_DAMAGE, 0, 0x1)
	};
}
#undef ADD_BOOL
