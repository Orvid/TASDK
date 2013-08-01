#pragma once
namespace UnrealScript
{
	enum TrObject__DeviceTargeterType : byte
	{
		TRDTT_None = 0,
		TRDTT_Self = 1,
		TRDTT_Friend = 2,
		TRDTT_Enemy = 3,
		TRDTT_Enemy_And_Self = 4,
		TRDTT_Friend_Only = 5,
		TRDTT_All = 6,
		TRDTT_MAX = 7,
	};
}
