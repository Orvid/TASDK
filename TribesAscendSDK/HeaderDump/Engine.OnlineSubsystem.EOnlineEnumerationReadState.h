#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__EOnlineEnumerationReadState : byte
	{
		OERS_NotStarted = 0,
		OERS_InProgress = 1,
		OERS_Done = 2,
		OERS_Failed = 3,
		OERS_MAX = 4,
	};
}
