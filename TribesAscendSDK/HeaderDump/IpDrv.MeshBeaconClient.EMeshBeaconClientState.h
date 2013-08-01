#pragma once
namespace UnrealScript
{
	enum MeshBeaconClient__EMeshBeaconClientState : byte
	{
		MBCS_None = 0,
		MBCS_Connecting = 1,
		MBCS_Connected = 2,
		MBCS_ConnectionFailed = 3,
		MBCS_AwaitingResponse = 4,
		MBCS_Closed = 5,
		MBCS_MAX = 6,
	};
}
