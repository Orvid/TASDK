#pragma once
#include "Core.Object.Color.h"
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
	struct WorldInfo__LightmassWorldInfoSettings
	{
	public:
		ADD_STRUCT(float, StaticLightingLevelScale, 0)
		ADD_STRUCT(int, NumIndirectLightingBounces, 4)
		ADD_STRUCT(Object__Color, EnvironmentColor, 8)
		ADD_STRUCT(float, EnvironmentIntensity, 12)
		ADD_STRUCT(float, EmissiveBoost, 16)
		ADD_STRUCT(float, DiffuseBoost, 20)
		ADD_STRUCT(float, SpecularBoost, 24)
		ADD_STRUCT(float, IndirectNormalInfluenceBoost, 28)
		ADD_BOOL(bUseNormalMapsForSimpleLightMaps, 32, 0x1)
		ADD_BOOL(bUseAmbientOcclusion, 32, 0x2)
		ADD_BOOL(bEnableImageReflectionShadowing, 32, 0x4)
		ADD_STRUCT(float, DirectIlluminationOcclusionFraction, 36)
		ADD_STRUCT(float, IndirectIlluminationOcclusionFraction, 40)
		ADD_STRUCT(float, OcclusionExponent, 44)
		ADD_STRUCT(float, FullyOccludedSamplesFraction, 48)
		ADD_STRUCT(float, MaxOcclusionDistance, 52)
		ADD_BOOL(bVisualizeMaterialDiffuse, 56, 0x1)
		ADD_BOOL(bVisualizeAmbientOcclusion, 56, 0x2)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
