#pragma once
namespace UnrealScript
{
	enum AnimSequence__AnimationKeyFormat : byte
	{
		AKF_ConstantKeyLerp = 0,
		AKF_VariableKeyLerp = 1,
		AKF_PerTrackCompression = 2,
		AKF_MAX = 3,
	};
}
