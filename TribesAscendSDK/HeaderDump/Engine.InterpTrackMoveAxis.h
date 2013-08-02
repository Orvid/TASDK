#pragma once
namespace UnrealScript
{
	class InterpTrackMoveAxis;
}
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.InterpTrackMove.InterpLookupTrack.h"
#include "Engine.InterpTrackMoveAxis.EInterpMoveAxis.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMoveAxis : public InterpTrackFloatBase
	{
	public:
		typedef InterpTrackMoveAxis__EInterpMoveAxis EInterpMoveAxis;
		ADD_STRUCT(InterpTrackMove__InterpLookupTrack, LookupTrack, 152)
		ADD_STRUCT(InterpTrackMoveAxis__EInterpMoveAxis, MoveAxis, 148)
	};
}
#undef ADD_STRUCT
