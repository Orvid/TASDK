#pragma once
namespace UnrealScript
{
	enum TrObject__EffectCalcMethod : byte
	{
		TRCM_NA = 0,
		TRCM_ADD = 1,
		TRCM_SUBTRACT = 2,
		TRCM_PERC_INCREASE = 3,
		TRCM_PERC_DECREASE = 4,
		TRCM_STATIC = 5,
		TRCM_MAX = 6,
	};
}
