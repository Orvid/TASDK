#pragma once
namespace UnrealScript
{
	class TextureFactory;
}
#include "Core.Factory.h"
#include "UnrealEd.TextureFactory.Blending.h"
#include "UnrealEd.TextureFactory.LODGroup.h"
#include "UnrealEd.TextureFactory.LightingModel.h"
#include "UnrealEd.TextureFactory.TextureCompressionSettings.h"
#include "UnrealEd.TextureFactory.TextureMipGenSettings.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureFactory : public Factory
	{
	public:
		typedef TextureFactory__TextureCompressionSettings TextureCompressionSettings;
		typedef TextureFactory__LODGroup LODGroup;
		typedef TextureFactory__Blending Blending;
		typedef TextureFactory__LightingModel LightingModel;
		typedef TextureFactory__TextureMipGenSettings TextureMipGenSettings;
		ADD_BOOL(NoCompression, 112, 0x1)
		ADD_BOOL(CompressionNoAlpha, 116, 0x1)
		ADD_STRUCT(TextureFactory__TextureCompressionSettings, CompressionSettings, 124)
		ADD_BOOL(DeferCompression, 120, 0x1)
		ADD_BOOL(Create Material?, 128, 0x1)
		ADD_BOOL(RGB To Diffuse, 132, 0x1)
		ADD_BOOL(RGB To Emissive, 136, 0x1)
		ADD_BOOL(Alpha To Specular, 140, 0x1)
		ADD_BOOL(Alpha To Emissive, 144, 0x1)
		ADD_BOOL(Alpha To Opacity, 148, 0x1)
		ADD_BOOL(Alpha To Opacity Mask, 152, 0x1)
		ADD_BOOL(Two Sided?, 156, 0x1)
		ADD_STRUCT(TextureFactory__Blending, Blending, 160)
		ADD_STRUCT(TextureFactory__LightingModel, Lighting Model, 161)
		ADD_STRUCT(TextureFactory__LODGroup, LODGroup, 162)
		ADD_BOOL(FlipBook, 164, 0x1)
		ADD_BOOL(LightMap, 168, 0x1)
		ADD_BOOL(Dither Mip-maps alpha?, 172, 0x1)
		ADD_BOOL(Preserve border R, 176, 0x1)
		ADD_BOOL(Preserve border G, 180, 0x1)
		ADD_BOOL(Preserve border B, 184, 0x1)
		ADD_BOOL(Preserve border A, 188, 0x1)
		ADD_STRUCT(TextureFactory__TextureMipGenSettings, MipGenSettings, 192)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
