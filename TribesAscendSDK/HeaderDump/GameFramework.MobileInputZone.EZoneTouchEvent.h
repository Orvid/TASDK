#pragma once
namespace UnrealScript
{
	enum MobileInputZone__EZoneTouchEvent : byte
	{
		ZoneEvent_Touch = 0,
		ZoneEvent_Update = 1,
		ZoneEvent_Stationary = 2,
		ZoneEvent_UnTouch = 3,
		ZoneEvent_Cancelled = 4,
		ZoneEvent_MAX = 5,
	};
}
