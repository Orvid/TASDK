#pragma once
#include "Engine.Actor.RigidBodyState.h"
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
	struct SVehicle__VehicleState
	{
	public:
		ADD_STRUCT(int, ServerView, 72)
		ADD_BOOL(bServerHandbrake, 68, 0x1)
		ADD_STRUCT(byte, ServerRise, 67)
		ADD_STRUCT(byte, ServerSteering, 66)
		ADD_STRUCT(byte, ServerGas, 65)
		ADD_STRUCT(byte, ServerBrake, 64)
		ADD_STRUCT(Actor__RigidBodyState, RBState, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
