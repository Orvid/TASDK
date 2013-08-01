#pragma once
namespace UnrealScript
{
	enum CoverLink__ECoverLocationDescription : byte
	{
		CoverDesc_None = 0,
		CoverDesc_InWindow = 1,
		CoverDesc_InDoorway = 2,
		CoverDesc_BehindCar = 3,
		CoverDesc_BehindTruck = 4,
		CoverDesc_OnTruck = 5,
		CoverDesc_BehindBarrier = 6,
		CoverDesc_BehindColumn = 7,
		CoverDesc_BehindCrate = 8,
		CoverDesc_BehindWall = 9,
		CoverDesc_BehindStatue = 10,
		CoverDesc_BehindSandbags = 11,
		CoverDesc_MAX = 12,
	};
}
