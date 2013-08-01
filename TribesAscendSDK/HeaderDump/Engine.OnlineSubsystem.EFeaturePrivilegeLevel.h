#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__EFeaturePrivilegeLevel : byte
	{
		FPL_Disabled = 0,
		FPL_EnabledFriendsOnly = 1,
		FPL_Enabled = 2,
		FPL_MAX = 3,
	};
}
