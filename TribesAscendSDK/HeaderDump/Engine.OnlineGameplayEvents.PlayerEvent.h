#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameplayEvents__PlayerEvent
	{
	public:
		ADD_STRUCT(int, PlayerPitchAndRoll, 20)
		ADD_STRUCT(int, PlayerIndexAndYaw, 16)
		ADD_STRUCT(Vector, EventLocation, 4)
		ADD_STRUCT(float, EventTime, 0)
	};
}
#undef ADD_STRUCT
