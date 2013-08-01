#pragma once
namespace UnrealScript
{
	enum InterpTrackVisibility__EVisibilityTrackCondition : byte
	{
		EVTC_Always = 0,
		EVTC_GoreEnabled = 1,
		EVTC_GoreDisabled = 2,
		EVTC_MAX = 3,
	};
}
