#pragma once
namespace UnrealScript
{
	class InterpTrackVisibility;
}
#include "Engine.InterpTrack.h"
#include "Engine.InterpTrackVisibility.EVisibilityTrackAction.h"
#include "Engine.InterpTrackVisibility.EVisibilityTrackCondition.h"
#include "Engine.InterpTrackVisibility.VisibilityTrackKey.h"
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
	class InterpTrackVisibility : public InterpTrack
	{
	public:
		typedef InterpTrackVisibility__EVisibilityTrackCondition EVisibilityTrackCondition;
		typedef InterpTrackVisibility__EVisibilityTrackAction EVisibilityTrackAction;
		typedef InterpTrackVisibility__VisibilityTrackKey VisibilityTrackKey;
		ADD_STRUCT(ScriptArray<InterpTrackVisibility__VisibilityTrackKey>, VisibilityTrack, 128)
		ADD_BOOL(bFireEventsWhenJumpingForwards, 140, 0x4)
		ADD_BOOL(bFireEventsWhenBackwards, 140, 0x2)
		ADD_BOOL(bFireEventsWhenForwards, 140, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
