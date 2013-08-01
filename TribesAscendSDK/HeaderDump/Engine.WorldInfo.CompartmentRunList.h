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
	struct WorldInfo__CompartmentRunList
	{
	public:
		ADD_BOOL(RigidBody, 0, 0x1)
		ADD_BOOL(Fluid, 0, 0x2)
		ADD_BOOL(Cloth, 0, 0x4)
		ADD_BOOL(SoftBody, 0, 0x8)
	};
}
#undef ADD_BOOL
