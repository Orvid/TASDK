#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__ELoginStatus : byte
	{
		LS_NotLoggedIn = 0,
		LS_UsingLocalProfile = 1,
		LS_LoggedIn = 2,
		LS_MAX = 3,
	};
}
