#pragma once
namespace UnrealScript
{
	enum DistributionVector__EDistributionVectorLockFlags : byte
	{
		EDVLF_None = 0,
		EDVLF_XY = 1,
		EDVLF_XZ = 2,
		EDVLF_YZ = 3,
		EDVLF_XYZ = 4,
		EDVLF_MAX = 5,
	};
}
