#pragma once
namespace UnrealScript
{
	struct GameStatsAggregator__PawnEvents;
}
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStatsAggregator__PawnEvents
	{
	public:
		ADD_STRUCT(ScriptArray<GameStatsAggregator__GameEvents>, EventsByPawnClass, 60)
		ADD_STRUCT(GameStatsAggregator__GameEvents, TotalEvents, 0)
	};
}
#undef ADD_STRUCT
