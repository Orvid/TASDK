#pragma once
namespace UnrealScript
{
	enum TrMusicManager__ETgMusicState : byte
	{
		MUSICSTATE_BattleLow = 0,
		MUSICSTATE_BattleMed = 1,
		MUSICSTATE_BattleHigh = 2,
		MUSICSTATE_FlagPossession = 3,
		MUSICSTATE_DeathDirge = 4,
		MUSICSTATE_TeamWonMatch = 5,
		MUSICSTATE_TeamLostMatch = 6,
		MUSICSTATE_NoMusic = 7,
		MUSICSTATE_Ambient = 8,
		MUSICSTATE_MAX = 9,
	};
}
