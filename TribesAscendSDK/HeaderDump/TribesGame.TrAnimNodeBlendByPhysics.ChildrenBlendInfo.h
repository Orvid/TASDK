#pragma once
namespace UnrealScript
{
	struct TrAnimNodeBlendByPhysics__ChildrenBlendInfo;
}
#include "Engine.Actor.EPhysics.h"
#include "TribesGame.TrAnimNodeBlendByPhysics.ChildBlendInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrAnimNodeBlendByPhysics__ChildrenBlendInfo
	{
	public:
		ADD_STRUCT(ScriptArray<TrAnimNodeBlendByPhysics__ChildBlendInfo>, m_ChildBlendInfo, 4)
		ADD_STRUCT(Actor__EPhysics, m_PhysicsState, 0)
	};
}
#undef ADD_STRUCT
