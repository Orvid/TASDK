#pragma once
namespace UnrealScript
{
	enum EngineTypes__EMobileValueSource : byte
	{
		MVS_Constant = 0,
		MVS_VertexColorRed = 1,
		MVS_VertexColorGreen = 2,
		MVS_VertexColorBlue = 3,
		MVS_VertexColorAlpha = 4,
		MVS_BaseTextureRed = 5,
		MVS_BaseTextureGreen = 6,
		MVS_BaseTextureBlue = 7,
		MVS_BaseTextureAlpha = 8,
		MVS_MaskTextureRed = 9,
		MVS_MaskTextureGreen = 10,
		MVS_MaskTextureBlue = 11,
		MVS_MaskTextureAlpha = 12,
		MVS_NormalTextureAlpha = 13,
		MVS_MAX = 14,
	};
}
