#pragma once
namespace UnrealScript
{
	class NavMeshGoalFilter_OutOfViewFrom;
}
#include "Core.Object.Pointer.h"
#include "Engine.NavMeshGoal_Filter.h"
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_OutOfViewFrom : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(Vector, OutOfViewLocation, 76)
		ADD_STRUCT(Object__Pointer, GoalPoly, 72)
		bool MustBeHiddenFromThisPoint(class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InOutOfViewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21003);
			byte params[20] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(Vector*)&params[4] = InOutOfViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
