#pragma once
#include "Engine.InterpTrackHeadTracking.EHeadTrackingAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackHeadTracking__HeadTrackingKey
	{
	public:
		ADD_STRUCT(InterpTrackHeadTracking__EHeadTrackingAction, Action, 4)
		ADD_STRUCT(float, Time, 0)
	};
}
#undef ADD_STRUCT
