#pragma once
namespace UnrealScript
{
	enum MobileInputZone__EZoneState : byte
	{
		ZoneState_Inactive = 0,
		ZoneState_Activating = 1,
		ZoneState_Active = 2,
		ZoneState_Deactivating = 3,
		ZoneState_MAX = 4,
	};
}
