#pragma once
namespace UnrealScript
{
	struct EngineTypes__LightmassPrimitiveSettings;
}
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
	struct EngineTypes__LightmassPrimitiveSettings
	{
	public:
		ADD_STRUCT(float, FullyOccludedSamplesFraction, 24)
		ADD_STRUCT(float, SpecularBoost, 20)
		ADD_STRUCT(float, DiffuseBoost, 16)
		ADD_STRUCT(float, EmissiveBoost, 12)
		ADD_STRUCT(float, EmissiveLightExplicitInfluenceRadius, 8)
		ADD_STRUCT(float, EmissiveLightFalloffExponent, 4)
		ADD_BOOL(bUseEmissiveForStaticLighting, 0, 0x4)
		ADD_BOOL(bShadowIndirectOnly, 0, 0x2)
		ADD_BOOL(bUseTwoSidedLighting, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
