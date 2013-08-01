#pragma once
#include "Engine.InterpTrackInst.h"
#include "Engine.InterpTrackHeadTracking.EHeadTrackingAction.h"
#include "Engine.SkelControlLookAt.h"
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
	class InterpTrackInstHeadTracking : public InterpTrackInst
	{
	public:
		ADD_STRUCT(ScriptArray<class SkelControlLookAt*>, TrackControls, 128)
		ADD_STRUCT(float, LastUpdatePosition, 140)
		ADD_STRUCT(InterpTrackHeadTracking__EHeadTrackingAction, Action, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
