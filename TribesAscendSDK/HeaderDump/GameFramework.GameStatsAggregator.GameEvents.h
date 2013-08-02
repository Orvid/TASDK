#pragma once
namespace UnrealScript
{
	struct GameStatsAggregator__GameEvents;
}
#include "Core.Object.Map_Mirror.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStatsAggregator__GameEvents
	{
	public:
		ADD_STRUCT(Object__Map_Mirror, Events, 0)
	};
}
#undef ADD_STRUCT
