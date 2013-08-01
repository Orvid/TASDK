#pragma once
#include "Engine.Surface.h"
#include "Engine.Texture.TextureGroup.h"
#include "Core.Object.Guid.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture.TextureMipGenSettings.h"
#include "Core.Object.UntypedBulkData_Mirror.h"
#include "Engine.Texture.TextureFilter.h"
#include "Engine.Texture.TextureCompressionSettings.h"
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
	class Texture : public Surface
	{
	public:
		ADD_STRUCT(int, InternalFormatLODBias, 232)
		ADD_STRUCT(float, AdjustHue, 228)
		ADD_STRUCT(float, AdjustRGBCurve, 224)
		ADD_STRUCT(float, AdjustSaturation, 220)
		ADD_STRUCT(float, AdjustVibrance, 216)
		ADD_STRUCT(float, AdjustBrightnessCurve, 212)
		ADD_STRUCT(float, AdjustBrightness, 208)
		ADD_STRUCT(Object__Guid, LightingGuid, 192)
		ADD_STRUCT(Object__Pointer, Resource, 188)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 176)
		ADD_STRUCT(ScriptString*, SourceFilePath, 164)
		ADD_STRUCT(int, NumCinematicMipLevels, 160)
		ADD_STRUCT(int, CachedCombinedLODBias, 156)
		ADD_STRUCT(int, LODBias, 152)
		ADD_STRUCT(Texture__TextureMipGenSettings, MipGenSettings, 151)
		ADD_STRUCT(Texture__TextureGroup, LODGroup, 150)
		ADD_STRUCT(Texture__TextureFilter, Filter, 149)
		ADD_STRUCT(Texture__TextureCompressionSettings, CompressionSettings, 148)
		ADD_STRUCT(Object__UntypedBulkData_Mirror, SourceArt, 96)
		ADD_STRUCT(float, UnpackMax, 80)
		ADD_STRUCT(float, UnpackMin, 64)
		ADD_BOOL(bUseCinematicMipLevels, 60, 0x20000)
		ADD_BOOL(bAsyncResourceReleaseHasBeenStarted, 60, 0x10000)
		ADD_BOOL(bForcePVRTC4, 60, 0x8000)
		ADD_BOOL(bNoTiling, 60, 0x4000)
		ADD_BOOL(bPreserveBorderA, 60, 0x2000)
		ADD_BOOL(bPreserveBorderB, 60, 0x1000)
		ADD_BOOL(bPreserveBorderG, 60, 0x800)
		ADD_BOOL(bPreserveBorderR, 60, 0x400)
		ADD_BOOL(bDitherMipMapAlpha, 60, 0x200)
		ADD_BOOL(NeverStream, 60, 0x100)
		ADD_BOOL(DeferCompression, 60, 0x80)
		ADD_BOOL(CompressionFullDynamicRange, 60, 0x40)
		ADD_BOOL(CompressionNoMipmaps, 60, 0x20)
		ADD_BOOL(CompressionNone, 60, 0x10)
		ADD_BOOL(CompressionNoAlpha, 60, 0x8)
		ADD_BOOL(bIsSourceArtUncompressed, 60, 0x4)
		ADD_BOOL(RGBE, 60, 0x2)
		ADD_BOOL(SRGB, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
