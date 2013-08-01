#pragma once
namespace UnrealScript
{
	enum TrArenaStats__ManGraphicState : byte
	{
		ManGraphic_Hidden = 0,
		ManGraphic_HasSpawnsLeft = 1,
		ManGraphic_OutOfSpawns = 2,
		ManGraphic_CrossedOffList = 3,
		ManGraphic_MAX = 4,
	};
}
