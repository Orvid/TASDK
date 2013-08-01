#pragma once
namespace UnrealScript
{
	enum PartyBeacon__EPartyReservationResult : byte
	{
		PRR_GeneralError = 0,
		PRR_PartyLimitReached = 1,
		PRR_IncorrectPlayerCount = 2,
		PRR_RequestTimedOut = 3,
		PRR_ReservationDuplicate = 4,
		PRR_ReservationNotFound = 5,
		PRR_ReservationAccepted = 6,
		PRR_ReservationDenied = 7,
		PRR_MAX = 8,
	};
}
