#pragma once
#include "Engine.Actor.ActorReference.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverLink__CoverReference : public Actor__ActorReference
	{
	public:
		ADD_STRUCT(int, SlotIdx, 20)
	};
}
#undef ADD_STRUCT
