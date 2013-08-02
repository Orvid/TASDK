#pragma once
namespace UnrealScript
{
	class GameStatsAggregator;
}
#include "Core.Object.Map_Mirror.h"
#include "Engine.GameplayEvents.GameplayEventMetaData.h"
#include "Engine.GameplayEventsHandler.h"
#include "GameFramework.GameStateObject.h"
#include "GameFramework.GameStatsAggregator.AggregateEventMapping.h"
#include "GameFramework.GameStatsAggregator.DamageEvents.h"
#include "GameFramework.GameStatsAggregator.GameEvent.h"
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#include "GameFramework.GameStatsAggregator.PawnEvents.h"
#include "GameFramework.GameStatsAggregator.PlayerEvents.h"
#include "GameFramework.GameStatsAggregator.ProjectileEvents.h"
#include "GameFramework.GameStatsAggregator.TeamEvents.h"
#include "GameFramework.GameStatsAggregator.WeaponEvents.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameStatsAggregator : public GameplayEventsHandler
	{
	public:
		typedef GameStatsAggregator__AggregateEventMapping AggregateEventMapping;
		typedef GameStatsAggregator__TeamEvents TeamEvents;
		typedef GameStatsAggregator__PlayerEvents PlayerEvents;
		typedef GameStatsAggregator__DamageEvents DamageEvents;
		typedef GameStatsAggregator__PawnEvents PawnEvents;
		typedef GameStatsAggregator__ProjectileEvents ProjectileEvents;
		typedef GameStatsAggregator__WeaponEvents WeaponEvents;
		typedef GameStatsAggregator__GameEvents GameEvents;
		typedef GameStatsAggregator__GameEvent GameEvent;
		static const auto GAMEEVENT_AGGREGATED_DATA = 10000;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_TIMEALIVE = 10001;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_KILLS = 10002;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_DEATHS = 10003;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_MATCH_WON = 10004;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_ROUND_WON = 10005;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_NORMALKILL = 10006;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_WASNORMALKILL = 10007;
		static const auto GAMEEVENT_AGGREGATED_TEAM_KILLS = 10100;
		static const auto GAMEEVENT_AGGREGATED_TEAM_DEATHS = 10101;
		static const auto GAMEEVENT_AGGREGATED_TEAM_GAME_SCORE = 10102;
		static const auto GAMEEVENT_AGGREGATED_TEAM_MATCH_WON = 10103;
		static const auto GAMEEVENT_AGGREGATED_TEAM_ROUND_WON = 10104;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_KILLS = 10200;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEATHS = 10201;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEALT_WEAPON_DAMAGE = 10202;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEALT_MELEE_DAMAGE = 10203;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WEAPON_DAMAGE = 10204;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_MELEE_DAMAGE = 10205;
		static const auto GAMEEVENT_AGGREGATED_WEAPON_FIRED = 10300;
		static const auto GAMEEVENT_AGGREGATED_PAWN_SPAWN = 10400;
		static const auto GAMEEVENT_AGGREGATED_GAME_SPECIFIC = 11000;
		ADD_STRUCT(ScriptArray<GameStatsAggregator__AggregateEventMapping>, AggregatesList, 92)
		ADD_STRUCT(ScriptArray<GameplayEvents__GameplayEventMetaData>, AggregateEvents, 164)
		ADD_STRUCT(ScriptArray<GameStatsAggregator__TeamEvents>, AllTeamEvents, 236)
		ADD_STRUCT(ScriptArray<GameStatsAggregator__PlayerEvents>, AllPlayerEvents, 248)
		ADD_STRUCT(GameStatsAggregator__DamageEvents, AllDamageEvents, 476)
		ADD_STRUCT(GameStatsAggregator__PawnEvents, AllPawnEvents, 404)
		ADD_STRUCT(GameStatsAggregator__ProjectileEvents, AllProjectileEvents, 332)
		ADD_STRUCT(GameStatsAggregator__WeaponEvents, AllWeaponEvents, 260)
		ADD_STRUCT(GameStatsAggregator__GameEvents, AllGameEvents, 176)
		ADD_STRUCT(Object__Map_Mirror, AggregateEventsMapping, 104)
		ADD_OBJECT(GameStateObject, GameState, 88)
		void PreProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAggregateMappingIDs(int EventID, int& AggregateID, int& TargetAggregateID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32035);
			byte params[16] = { NULL };
			*(int*)params = EventID;
			*(int*)&params[4] = AggregateID;
			*(int*)&params[8] = TargetAggregateID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			AggregateID = *(int*)&params[4];
			TargetAggregateID = *(int*)&params[8];
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
