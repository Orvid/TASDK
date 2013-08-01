#pragma once
namespace UnrealScript
{
	enum PartyBeacon__EReservationPacketType : byte
	{
		RPT_UnknownPacketType = 0,
		RPT_ClientReservationRequest = 1,
		RPT_ClientReservationUpdateRequest = 2,
		RPT_ClientCancellationRequest = 3,
		RPT_HostReservationResponse = 4,
		RPT_HostReservationCountUpdate = 5,
		RPT_HostTravelRequest = 6,
		RPT_HostIsReady = 7,
		RPT_HostHasCancelled = 8,
		RPT_Heartbeat = 9,
		RPT_MAX = 10,
	};
}
