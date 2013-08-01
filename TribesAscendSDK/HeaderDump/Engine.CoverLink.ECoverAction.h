#pragma once
namespace UnrealScript
{
	enum CoverLink__ECoverAction : byte
	{
		CA_Default = 0,
		CA_BlindLeft = 1,
		CA_BlindRight = 2,
		CA_LeanLeft = 3,
		CA_LeanRight = 4,
		CA_PopUp = 5,
		CA_BlindUp = 6,
		CA_PeekLeft = 7,
		CA_PeekRight = 8,
		CA_PeekUp = 9,
		CA_MAX = 10,
	};
}
