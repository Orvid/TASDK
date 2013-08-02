#pragma once
namespace UnrealScript
{
	struct UDKVehicle__VehicleSeatAnimInfo;
}
#include "Engine.AnimSet.h"
#include "Engine.AnimTree.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct UDKVehicle__VehicleSeatAnimInfo
	{
	public:
		ADD_OBJECT(AnimTree, SeatAnimTree, 16)
		ADD_OBJECT(AnimSet, SeatAnimSet, 12)
		ADD_STRUCT(int, TeamType, 8)
		ADD_STRUCT(int, ArmorType, 4)
		ADD_BOOL(bClearAnimSet, 0, 0x4)
		ADD_BOOL(bIsFactionDependent, 0, 0x2)
		ADD_BOOL(bIsArmorDependent, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
