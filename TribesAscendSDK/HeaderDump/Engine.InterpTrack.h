#pragma once
namespace UnrealScript
{
	class InterpTrack;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.InterpTrack.ETrackActiveCondition.h"
#include "Engine.InterpTrack.SubTrackGroup.h"
#include "Engine.InterpTrack.SupportedSubTrackInfo.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrack : public Object
	{
	public:
		typedef InterpTrack__ETrackActiveCondition ETrackActiveCondition;
		typedef InterpTrack__SubTrackGroup SubTrackGroup;
		typedef InterpTrack__SupportedSubTrackInfo SupportedSubTrackInfo;
		ADD_STRUCT(ScriptArray<class InterpTrack*>, SubTracks, 68)
		ADD_STRUCT(ScriptArray<InterpTrack__SubTrackGroup>, SubTrackGroups, 80)
		ADD_STRUCT(ScriptArray<InterpTrack__SupportedSubTrackInfo>, SupportedSubTracks, 92)
		ADD_BOOL(bIsCollapsed, 124, 0x100)
		ADD_BOOL(bIsRecording, 124, 0x80)
		ADD_BOOL(bIsSelected, 124, 0x40)
		ADD_BOOL(bVisible, 124, 0x20)
		ADD_BOOL(bSubTrackOnly, 124, 0x10)
		ADD_BOOL(bIsAnimControlTrack, 124, 0x8)
		ADD_BOOL(bDisableTrack, 124, 0x4)
		ADD_BOOL(bDirGroupOnly, 124, 0x2)
		ADD_BOOL(bOnePerGroup, 124, 0x1)
		ADD_STRUCT(ScriptString*, TrackTitle, 112)
		ADD_STRUCT(InterpTrack__ETrackActiveCondition, ActiveCondition, 108)
		ADD_OBJECT(ScriptClass, TrackInstClass, 104)
		ADD_STRUCT(Object__Pointer, CurveEdVTable, 64)
		ADD_STRUCT(Object__Pointer, VfTable_FInterpEdInputInterface, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
