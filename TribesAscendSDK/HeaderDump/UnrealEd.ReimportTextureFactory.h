#pragma once
namespace UnrealScript
{
	class ReimportTextureFactory;
}
#include "UnrealEd.ReimportTextureFactory.Blending.h"
#include "UnrealEd.ReimportTextureFactory.LightingModel.h"
#include "UnrealEd.ReimportTextureFactory.TextureCompressionSettings.h"
#include "UnrealEd.ReimportTextureFactory.TextureMipGenSettings.h"
#include "UnrealEd.TextureFactory.h"
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
	class ReimportTextureFactory : public TextureFactory
	{
	public:
		typedef ReimportTextureFactory__TextureCompressionSettings TextureCompressionSettings;
		typedef ReimportTextureFactory__Blending Blending;
		typedef ReimportTextureFactory__LightingModel LightingModel;
		typedef ReimportTextureFactory__TextureMipGenSettings TextureMipGenSettings;
		ADD_BOOL(NoCompression, 112, 0x1)
		ADD_BOOL(CompressionNoAlpha, 116, 0x1)
		ADD_STRUCT(ReimportTextureFactory__TextureCompressionSettings, CompressionSettings, 124)
		ADD_BOOL(DeferCompression, 120, 0x1)
		ADD_BOOL(Create Material?, 128, 0x1)
		ADD_BOOL(RGB To Diffuse, 132, 0x1)
		ADD_BOOL(RGB To Emissive, 136, 0x1)
		ADD_BOOL(Alpha To Specular, 140, 0x1)
		ADD_BOOL(Alpha To Emissive, 144, 0x1)
		ADD_BOOL(Alpha To Opacity, 148, 0x1)
		ADD_BOOL(Alpha To Opacity Mask, 152, 0x1)
		ADD_BOOL(Two Sided?, 156, 0x1)
		ADD_STRUCT(ReimportTextureFactory__Blending, Blending, 160)
		ADD_STRUCT(ReimportTextureFactory__LightingModel, Lighting Model, 161)
		ADD_BOOL(FlipBook, 164, 0x1)
		ADD_STRUCT(ReimportTextureFactory__TextureMipGenSettings, MipGenSettings, 192)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
