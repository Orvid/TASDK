#pragma once
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
	struct MaterialInterface__LightmassMaterialInterfaceSettings
	{
	public:
		ADD_BOOL(bOverrideDistanceFieldPenumbraScale, 24, 0x20)
		ADD_BOOL(bOverrideExportResolutionScale, 24, 0x10)
		ADD_BOOL(bOverrideSpecularBoost, 24, 0x8)
		ADD_BOOL(bOverrideDiffuseBoost, 24, 0x4)
		ADD_BOOL(bOverrideEmissiveBoost, 24, 0x2)
		ADD_BOOL(bOverrideCastShadowAsMasked, 24, 0x1)
		ADD_STRUCT(float, DistanceFieldPenumbraScale, 20)
		ADD_STRUCT(float, ExportResolutionScale, 16)
		ADD_STRUCT(float, SpecularBoost, 12)
		ADD_STRUCT(float, DiffuseBoost, 8)
		ADD_STRUCT(float, EmissiveBoost, 4)
		ADD_BOOL(bCastShadowAsMasked, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
