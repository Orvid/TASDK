#pragma once
namespace UnrealScript
{
	enum Texture__TextureCompressionSettings : byte
	{
		TC_Default = 0,
		TC_Normalmap = 1,
		TC_Displacementmap = 2,
		TC_NormalmapAlpha = 3,
		TC_Grayscale = 4,
		TC_HighDynamicRange = 5,
		TC_OneBitAlpha = 6,
		TC_NormalmapUncompressed = 7,
		TC_NormalmapBC5 = 8,
		TC_OneBitMonochrome = 9,
		TC_SimpleLightmapModification = 10,
		TC_VectorDisplacementmap = 11,
		TC_MAX = 12,
	};
}
