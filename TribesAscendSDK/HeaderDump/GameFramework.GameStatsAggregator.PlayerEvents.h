#pragma once
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#include "GameFramework.GameStatsAggregator.PawnEvents.h"
#include "GameFramework.GameStatsAggregator.ProjectileEvents.h"
#include "GameFramework.GameStatsAggregator.DamageEvents.h"
#include "GameFramework.GameStatsAggregator.WeaponEvents.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStatsAggregator__PlayerEvents
	{
	public:
		ADD_STRUCT(GameStatsAggregator__PawnEvents, PawnEvents, 348)
		ADD_STRUCT(GameStatsAggregator__ProjectileEvents, ProjectileEvents, 276)
		ADD_STRUCT(GameStatsAggregator__DamageEvents, DamageAsTargetEvents, 204)
		ADD_STRUCT(GameStatsAggregator__DamageEvents, DamageAsPlayerEvents, 132)
		ADD_STRUCT(GameStatsAggregator__WeaponEvents, WeaponEvents, 60)
		ADD_STRUCT(GameStatsAggregator__GameEvents, TotalEvents, 0)
	};
}
#undef ADD_STRUCT
