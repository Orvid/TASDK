#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__EOnlineServerConnectionStatus : byte
	{
		OSCS_NotConnected = 0,
		OSCS_Connected = 1,
		OSCS_ConnectionDropped = 2,
		OSCS_NoNetworkConnection = 3,
		OSCS_ServiceUnavailable = 4,
		OSCS_UpdateRequired = 5,
		OSCS_ServersTooBusy = 6,
		OSCS_DuplicateLoginDetected = 7,
		OSCS_InvalidUser = 8,
		OSCS_MAX = 9,
	};
}
