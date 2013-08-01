#pragma once
#include "Engine.InterpTrackMove.InterpLookupPoint.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackMove__InterpLookupTrack
	{
	public:
		ADD_STRUCT(ScriptArray<InterpTrackMove__InterpLookupPoint>, Points, 0)
	};
}
#undef ADD_STRUCT
