#pragma once
namespace UnrealScript
{
	enum EngineTypes__EMobileSpecularMask : byte
	{
		MSM_Constant = 0,
		MSM_Luminance = 1,
		MSM_DiffuseRed = 2,
		MSM_DiffuseGreen = 3,
		MSM_DiffuseBlue = 4,
		MSM_DiffuseAlpha = 5,
		MSM_MaskTextureRGB = 6,
		MSM_MAX = 7,
	};
}
