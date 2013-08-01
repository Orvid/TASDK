#pragma once
namespace UnrealScript
{
	enum TrStormControlPoint__ControlPointState : byte
	{
		ControlPointState_Neutral = 0,
		ControlPointState_FullyOwnedBE = 1,
		ControlPointState_FullyOwnedDS = 2,
		ControlPointState_TransitioningToBE = 3,
		ControlPointState_TransitioningToDS = 4,
		ControlPointState_MAX = 5,
	};
}
