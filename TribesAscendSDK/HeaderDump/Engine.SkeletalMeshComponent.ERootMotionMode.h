#pragma once
namespace UnrealScript
{
	enum SkeletalMeshComponent__ERootMotionMode : byte
	{
		RMM_Translate = 0,
		RMM_Velocity = 1,
		RMM_Ignore = 2,
		RMM_Accel = 3,
		RMM_Relative = 4,
		RMM_MAX = 5,
	};
}
