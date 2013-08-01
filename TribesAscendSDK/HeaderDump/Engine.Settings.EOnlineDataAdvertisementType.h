#pragma once
namespace UnrealScript
{
	enum Settings__EOnlineDataAdvertisementType : byte
	{
		ODAT_DontAdvertise = 0,
		ODAT_OnlineService = 1,
		ODAT_QoS = 2,
		ODAT_OnlineServiceAndQoS = 3,
		ODAT_MAX = 4,
	};
}
