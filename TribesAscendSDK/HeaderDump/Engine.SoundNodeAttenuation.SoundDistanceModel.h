#pragma once
namespace UnrealScript
{
	enum SoundNodeAttenuation__SoundDistanceModel : byte
	{
		ATTENUATION_Linear = 0,
		ATTENUATION_Logarithmic = 1,
		ATTENUATION_Inverse = 2,
		ATTENUATION_LogReverse = 3,
		ATTENUATION_NaturalSound = 4,
		ATTENUATION_MAX = 5,
	};
}
