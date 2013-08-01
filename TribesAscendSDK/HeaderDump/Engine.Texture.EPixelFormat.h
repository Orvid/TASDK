#pragma once
namespace UnrealScript
{
	enum Texture__EPixelFormat : byte
	{
		PF_Unknown = 0,
		PF_A32B32G32R32F = 1,
		PF_A8R8G8B8 = 2,
		PF_G8 = 3,
		PF_G16 = 4,
		PF_DXT1 = 5,
		PF_DXT3 = 6,
		PF_DXT5 = 7,
		PF_UYVY = 8,
		PF_FloatRGB = 9,
		PF_FloatRGBA = 10,
		PF_DepthStencil = 11,
		PF_ShadowDepth = 12,
		PF_FilteredShadowDepth = 13,
		PF_R32F = 14,
		PF_G16R16 = 15,
		PF_G16R16F = 16,
		PF_G16R16F_FILTER = 17,
		PF_G32R32F = 18,
		PF_A2B10G10R10 = 19,
		PF_A16B16G16R16 = 20,
		PF_D24 = 21,
		PF_R16F = 22,
		PF_R16F_FILTER = 23,
		PF_BC5 = 24,
		PF_V8U8 = 25,
		PF_A1 = 26,
		PF_MAX = 27,
	};
}
