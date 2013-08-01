#pragma once
namespace UnrealScript
{
	enum OnlineEventsInterfaceMcp__EEventUploadType : byte
	{
		EUT_GenericStats = 0,
		EUT_ProfileData = 1,
		EUT_MatchmakingData = 2,
		EUT_PlaylistPopulation = 3,
		EUT_MAX = 4,
	};
}
