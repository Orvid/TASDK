#pragma once
namespace UnrealScript
{
	enum UIDataStore_OnlineStats__EStatsFetchType : byte
	{
		SFT_Player = 0,
		SFT_CenteredOnPlayer = 1,
		SFT_Friends = 2,
		SFT_TopRankings = 3,
		SFT_MAX = 4,
	};
}
