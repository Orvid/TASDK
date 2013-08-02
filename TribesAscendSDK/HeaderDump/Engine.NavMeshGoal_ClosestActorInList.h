#pragma once
namespace UnrealScript
{
	class NavMeshGoal_ClosestActorInList;
}
#include "Core.Object.MultiMap_Mirror.h"
#include "Core.Object.Pointer.h"
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.NavMeshPathGoalEvaluator.BiasedGoalActor.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_ClosestActorInList : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(ScriptArray<NavMeshPathGoalEvaluator__BiasedGoalActor>, GoalList, 80)
		ADD_STRUCT(Object__Pointer, CachedAnchorPoly, 152)
		ADD_STRUCT(Object__MultiMap_Mirror, PolyToGoalActorMap, 92)
		class NavMeshGoal_ClosestActorInList* ClosestActorInList(class NavigationHandle* NavHandle, ScriptArray<NavMeshPathGoalEvaluator__BiasedGoalActor>& InGoalList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20946);
			byte params[20] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(ScriptArray<NavMeshPathGoalEvaluator__BiasedGoalActor>*)&params[4] = InGoalList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InGoalList = *(ScriptArray<NavMeshPathGoalEvaluator__BiasedGoalActor>*)&params[4];
			return *(class NavMeshGoal_ClosestActorInList**)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20952);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecycleInternal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20953);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
