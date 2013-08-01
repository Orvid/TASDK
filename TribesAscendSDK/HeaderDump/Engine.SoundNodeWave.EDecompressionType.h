#pragma once
namespace UnrealScript
{
	enum SoundNodeWave__EDecompressionType : byte
	{
		DTYPE_Setup = 0,
		DTYPE_Invalid = 1,
		DTYPE_Preview = 2,
		DTYPE_Native = 3,
		DTYPE_RealTime = 4,
		DTYPE_Procedural = 5,
		DTYPE_Xenon = 6,
		DTYPE_MAX = 7,
	};
}
