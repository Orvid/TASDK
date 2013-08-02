#pragma once
namespace UnrealScript
{
	struct Texture__TextureGroupContainer;
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
namespace UnrealScript
{
	struct Texture__TextureGroupContainer
	{
	public:
		ADD_BOOL(TEXTUREGROUP_ImageBasedReflection, 0, 0x4000000)
		ADD_BOOL(TEXTUREGROUP_Terrain_Weightmap, 0, 0x2000000)
		ADD_BOOL(TEXTUREGROUP_Terrain_Heightmap, 0, 0x1000000)
		ADD_BOOL(TEXTUREGROUP_ColorLookupTable, 0, 0x800000)
		ADD_BOOL(TEXTUREGROUP_Shadowmap, 0, 0x400000)
		ADD_BOOL(TEXTUREGROUP_ProcBuilding_LightMap, 0, 0x200000)
		ADD_BOOL(TEXTUREGROUP_ProcBuilding_Face, 0, 0x100000)
		ADD_BOOL(TEXTUREGROUP_MobileFlattened, 0, 0x80000)
		ADD_BOOL(TEXTUREGROUP_RenderTarget, 0, 0x40000)
		ADD_BOOL(TEXTUREGROUP_Lightmap, 0, 0x20000)
		ADD_BOOL(TEXTUREGROUP_UI, 0, 0x10000)
		ADD_BOOL(TEXTUREGROUP_Skybox, 0, 0x8000)
		ADD_BOOL(TEXTUREGROUP_EffectsNotFiltered, 0, 0x4000)
		ADD_BOOL(TEXTUREGROUP_Effects, 0, 0x2000)
		ADD_BOOL(TEXTUREGROUP_Cinematic, 0, 0x1000)
		ADD_BOOL(TEXTUREGROUP_VehicleSpecular, 0, 0x800)
		ADD_BOOL(TEXTUREGROUP_VehicleNormalMap, 0, 0x400)
		ADD_BOOL(TEXTUREGROUP_Vehicle, 0, 0x200)
		ADD_BOOL(TEXTUREGROUP_WeaponSpecular, 0, 0x100)
		ADD_BOOL(TEXTUREGROUP_WeaponNormalMap, 0, 0x80)
		ADD_BOOL(TEXTUREGROUP_Weapon, 0, 0x40)
		ADD_BOOL(TEXTUREGROUP_CharacterSpecular, 0, 0x20)
		ADD_BOOL(TEXTUREGROUP_CharacterNormalMap, 0, 0x10)
		ADD_BOOL(TEXTUREGROUP_Character, 0, 0x8)
		ADD_BOOL(TEXTUREGROUP_WorldSpecular, 0, 0x4)
		ADD_BOOL(TEXTUREGROUP_WorldNormalMap, 0, 0x2)
		ADD_BOOL(TEXTUREGROUP_World, 0, 0x1)
	};
}
#undef ADD_BOOL
