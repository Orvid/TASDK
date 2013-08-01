#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__ELanBeaconState : byte
	{
		LANB_NotUsingLanBeacon = 0,
		LANB_Hosting = 1,
		LANB_Searching = 2,
		LANB_MAX = 3,
	};
}
