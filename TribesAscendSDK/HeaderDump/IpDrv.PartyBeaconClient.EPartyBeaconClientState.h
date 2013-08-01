#pragma once
namespace UnrealScript
{
	enum PartyBeaconClient__EPartyBeaconClientState : byte
	{
		PBCS_None = 0,
		PBCS_Connecting = 1,
		PBCS_Connected = 2,
		PBCS_ConnectionFailed = 3,
		PBCS_AwaitingResponse = 4,
		PBCS_Closed = 5,
		PBCS_MAX = 6,
	};
}
