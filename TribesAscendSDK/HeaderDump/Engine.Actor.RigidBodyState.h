#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Actor__RigidBodyState
	{
	public:
		ADD_STRUCT(byte, bNewData, 56)
		ADD_STRUCT(Vector, AngVel, 44)
		ADD_STRUCT(Vector, LinVel, 32)
		ADD_STRUCT(Object__Quat, Quaternion, 16)
		ADD_STRUCT(Vector, Position, 0)
	};
}
#undef ADD_STRUCT
