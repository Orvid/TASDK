#pragma once
namespace UnrealScript
{
	enum MeshBeacon__EMeshBeaconConnectionResult : byte
	{
		MB_ConnectionResult_Succeeded = 0,
		MB_ConnectionResult_Duplicate = 1,
		MB_ConnectionResult_Timeout = 2,
		MB_ConnectionResult_Error = 3,
		MB_ConnectionResult_MAX = 4,
	};
}
