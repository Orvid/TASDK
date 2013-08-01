#pragma once
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
	struct ApexDestructibleAsset__NxDestructibleDepthParameters
	{
	public:
		ADD_BOOL(USER_FLAG_3, 0, 0x80)
		ADD_BOOL(USER_FLAG_2, 0, 0x40)
		ADD_BOOL(USER_FLAG_1, 0, 0x20)
		ADD_BOOL(USER_FLAG_0, 0, 0x10)
		ADD_BOOL(IGNORE_CONTACT_CALLBACKS, 0, 0x8)
		ADD_BOOL(IGNORE_RAYCAST_CALLBACKS, 0, 0x4)
		ADD_BOOL(IGNORE_POSE_UPDATES, 0, 0x2)
		ADD_BOOL(TAKE_IMPACT_DAMAGE, 0, 0x1)
	};
}
#undef ADD_BOOL
