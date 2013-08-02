#pragma once
namespace UnrealScript
{
	struct InterpTrackToggle__ToggleTrackKey;
}
#include "Engine.InterpTrackToggle.ETrackToggleAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackToggle__ToggleTrackKey
	{
	public:
		ADD_STRUCT(InterpTrackToggle__ETrackToggleAction, ToggleAction, 4)
		ADD_STRUCT(float, Time, 0)
	};
}
#undef ADD_STRUCT
