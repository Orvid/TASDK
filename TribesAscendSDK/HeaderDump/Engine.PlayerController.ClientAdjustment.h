#pragma once
#include "Engine.Actor.EPhysics.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
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
	struct PlayerController__ClientAdjustment
	{
	public:
		ADD_STRUCT(Actor__EPhysics, newPhysics, 4)
		ADD_STRUCT(Vector, NewLoc, 8)
		ADD_STRUCT(Vector, NewVel, 20)
		ADD_OBJECT(Actor, NewBase, 32)
		ADD_STRUCT(Vector, NewFloor, 36)
		ADD_STRUCT(float, TimeStamp, 0)
		ADD_STRUCT(byte, bAckGoodMove, 48)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
