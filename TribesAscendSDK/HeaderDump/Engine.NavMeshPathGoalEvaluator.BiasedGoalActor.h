#pragma once
namespace UnrealScript
{
	struct NavMeshPathGoalEvaluator__BiasedGoalActor;
}
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
	struct NavMeshPathGoalEvaluator__BiasedGoalActor
	{
	public:
		ADD_STRUCT(int, ExtraCost, 4)
		ADD_OBJECT(Actor, Goal, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
