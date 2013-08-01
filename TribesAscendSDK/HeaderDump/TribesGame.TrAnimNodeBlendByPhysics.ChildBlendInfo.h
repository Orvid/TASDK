#pragma once
#include "Engine.Actor.EPhysics.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrAnimNodeBlendByPhysics__ChildBlendInfo
	{
	public:
		ADD_STRUCT(float, m_fBlendTime, 4)
		ADD_STRUCT(Actor__EPhysics, m_PhysicsState, 0)
	};
}
#undef ADD_STRUCT
