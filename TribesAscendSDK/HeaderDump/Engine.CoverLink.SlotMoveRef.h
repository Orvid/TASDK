#pragma once
namespace UnrealScript
{
	struct CoverLink__SlotMoveRef;
}
#include "Engine.Actor.BasedPosition.h"
#include "Engine.Pylon.PolyReference.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverLink__SlotMoveRef
	{
	public:
		ADD_STRUCT(int, Direction, 76)
		ADD_STRUCT(Actor__BasedPosition, Dest, 24)
		ADD_STRUCT(Pylon__PolyReference, Poly, 0)
	};
}
#undef ADD_STRUCT
