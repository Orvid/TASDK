#pragma once
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.InterpTrackMoveAxis.EInterpMoveAxis.h"
#include "Engine.InterpTrackMove.InterpLookupTrack.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMoveAxis : public InterpTrackFloatBase
	{
	public:
		ADD_STRUCT(InterpTrackMove__InterpLookupTrack, LookupTrack, 152)
		ADD_STRUCT(InterpTrackMoveAxis__EInterpMoveAxis, MoveAxis, 148)
	};
}
#undef ADD_STRUCT
