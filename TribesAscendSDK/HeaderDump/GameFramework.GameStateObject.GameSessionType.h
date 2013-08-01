#pragma once
namespace UnrealScript
{
	enum GameStateObject__GameSessionType : byte
	{
		GT_SessionInvalid = 0,
		GT_SinglePlayer = 1,
		GT_Coop = 2,
		GT_Multiplayer = 3,
		GT_MAX = 4,
	};
}
