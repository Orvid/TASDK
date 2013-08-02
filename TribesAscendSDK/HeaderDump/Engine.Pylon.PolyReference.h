#pragma once
namespace UnrealScript
{
	struct Pylon__PolyReference;
}
#include "Engine.Actor.ActorReference.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Pylon__PolyReference
	{
	public:
		ADD_STRUCT(int, PolyId, 20)
		ADD_STRUCT(Actor__ActorReference, OwningPylon, 0)
	};
}
#undef ADD_STRUCT
