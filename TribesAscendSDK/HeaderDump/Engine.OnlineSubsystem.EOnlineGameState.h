#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__EOnlineGameState : byte
	{
		OGS_NoSession = 0,
		OGS_Pending = 1,
		OGS_Starting = 2,
		OGS_InProgress = 3,
		OGS_Ending = 4,
		OGS_Ended = 5,
		OGS_MAX = 6,
	};
}
