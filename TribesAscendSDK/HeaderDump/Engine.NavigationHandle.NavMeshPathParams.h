#pragma once
namespace UnrealScript
{
	struct NavigationHandle__NavMeshPathParams;
}
#include "Core.Object.Pointer.h"
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
	struct NavigationHandle__NavMeshPathParams
	{
	public:
		ADD_STRUCT(float, MaxHoverDistance, 44)
		ADD_STRUCT(float, MinWalkableZ, 40)
		ADD_STRUCT(float, MaxDropHeight, 36)
		ADD_STRUCT(Vector, SearchStart, 24)
		ADD_STRUCT(float, SearchLaneMultiplier, 20)
		ADD_STRUCT(Vector, SearchExtent, 8)
		ADD_BOOL(bAbleToSearch, 4, 0x4)
		ADD_BOOL(bNeedsMantleValidityTest, 4, 0x2)
		ADD_BOOL(bCanMantle, 4, 0x1)
		ADD_STRUCT(Object__Pointer, Interface, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
