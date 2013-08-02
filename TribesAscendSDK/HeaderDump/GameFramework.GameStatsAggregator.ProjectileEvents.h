#pragma once
namespace UnrealScript
{
	struct GameStatsAggregator__ProjectileEvents;
}
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStatsAggregator__ProjectileEvents
	{
	public:
		ADD_STRUCT(ScriptArray<GameStatsAggregator__GameEvents>, EventsByProjectileClass, 60)
		ADD_STRUCT(GameStatsAggregator__GameEvents, TotalEvents, 0)
	};
}
#undef ADD_STRUCT
