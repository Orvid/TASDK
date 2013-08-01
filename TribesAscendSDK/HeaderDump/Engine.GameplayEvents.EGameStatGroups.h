#pragma once
namespace UnrealScript
{
	enum GameplayEvents__EGameStatGroups : byte
	{
		GSG_EngineStats = 0,
		GSG_Game = 1,
		GSG_Team = 2,
		GSG_Player = 3,
		GSG_Weapon = 4,
		GSG_Damage = 5,
		GSG_Projectile = 6,
		GSG_Pawn = 7,
		GSG_GameSpecific = 8,
		GSG_Aggregate = 9,
		GSG_MAX = 10,
	};
}
