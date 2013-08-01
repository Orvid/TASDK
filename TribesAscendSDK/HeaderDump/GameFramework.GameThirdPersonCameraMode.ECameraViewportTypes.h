#pragma once
namespace UnrealScript
{
	enum GameThirdPersonCameraMode__ECameraViewportTypes : byte
	{
		CVT_16to9_Full = 0,
		CVT_16to9_VertSplit = 1,
		CVT_16to9_HorizSplit = 2,
		CVT_4to3_Full = 3,
		CVT_4to3_HorizSplit = 4,
		CVT_4to3_VertSplit = 5,
		CVT_MAX = 6,
	};
}
