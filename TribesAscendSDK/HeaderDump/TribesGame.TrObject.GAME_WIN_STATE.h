#pragma once
namespace UnrealScript
{
	enum TrObject__GAME_WIN_STATE : byte
	{
		GWS_NONE = 0,
		GWS_DEFENDER_WON = 1,
		GWS_ATTACKER_WON = 2,
		GWS_TIE = 3,
		GWS_MAX = 4,
	};
}
