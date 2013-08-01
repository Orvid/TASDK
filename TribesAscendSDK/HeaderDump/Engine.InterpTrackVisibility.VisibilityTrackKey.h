#pragma once
#include "Engine.InterpTrackVisibility.EVisibilityTrackCondition.h"
#include "Engine.InterpTrackVisibility.EVisibilityTrackAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackVisibility__VisibilityTrackKey
	{
	public:
		ADD_STRUCT(InterpTrackVisibility__EVisibilityTrackCondition, ActiveCondition, 5)
		ADD_STRUCT(InterpTrackVisibility__EVisibilityTrackAction, Action, 4)
		ADD_STRUCT(float, Time, 0)
	};
}
#undef ADD_STRUCT
