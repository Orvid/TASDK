#pragma once
namespace UnrealScript
{
	class Terrain;
}
#include "Core.Object.Color.h"
#include "Core.Object.Guid.h"
#include "Core.Object.Pointer.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#include "Engine.Info.h"
#include "Engine.LightComponent.LightingChannelContainer.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Terrain.AlphaMap.h"
#include "Engine.Terrain.CachedTerrainMaterialArray.h"
#include "Engine.Terrain.SelectedTerrainVertex.h"
#include "Engine.Terrain.TerrainDecoLayer.h"
#include "Engine.Terrain.TerrainDecoration.h"
#include "Engine.Terrain.TerrainDecorationInstance.h"
#include "Engine.Terrain.TerrainHeight.h"
#include "Engine.Terrain.TerrainInfoData.h"
#include "Engine.Terrain.TerrainLayer.h"
#include "Engine.Terrain.TerrainMaterialResource.h"
#include "Engine.Terrain.TerrainWeightedMaterial.h"
#include "Engine.TerrainWeightMapTexture.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Terrain : public Info
	{
	public:
		typedef Terrain__TerrainHeight TerrainHeight;
		typedef Terrain__TerrainInfoData TerrainInfoData;
		typedef Terrain__TerrainLayer TerrainLayer;
		typedef Terrain__TerrainDecoLayer TerrainDecoLayer;
		typedef Terrain__AlphaMap AlphaMap;
		typedef Terrain__TerrainWeightedMaterial TerrainWeightedMaterial;
		typedef Terrain__SelectedTerrainVertex SelectedTerrainVertex;
		typedef Terrain__TerrainDecorationInstance TerrainDecorationInstance;
		typedef Terrain__TerrainDecoration TerrainDecoration;
		typedef Terrain__TerrainMaterialResource TerrainMaterialResource;
		typedef Terrain__CachedTerrainMaterialArray CachedTerrainMaterialArray;
		ADD_STRUCT(ScriptArray<Terrain__TerrainHeight>, Heights, 476)
		ADD_STRUCT(ScriptArray<Terrain__TerrainInfoData>, InfoData, 488)
		ADD_STRUCT(ScriptArray<Terrain__TerrainLayer>, Layers, 500)
		ADD_STRUCT(ScriptArray<Terrain__TerrainDecoLayer>, DecoLayers, 516)
		ADD_STRUCT(ScriptArray<Terrain__AlphaMap>, AlphaMaps, 528)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, TerrainComponents, 540)
		ADD_STRUCT(ScriptArray<Terrain__TerrainWeightedMaterial>, WeightedMaterials, 560)
		ADD_STRUCT(ScriptArray<class TerrainWeightMapTexture*>, WeightedTextureMaps, 572)
		ADD_STRUCT(ScriptArray<Terrain__SelectedTerrainVertex>, SelectedVertices, 700)
		ADD_STRUCT(Object__Guid, LightingGuid, 716)
		ADD_STRUCT(Object__Color, WireframeColor, 712)
		ADD_STRUCT(int, EditorTessellationLevel, 696)
		ADD_STRUCT(Object__Pointer, ReleaseResourcesFence, 692)
		ADD_STRUCT(EngineTypes__LightmassPrimitiveSettings, LightmassSettings, 664)
		ADD_STRUCT(LightComponent__LightingChannelContainer, LightingChannels, 660)
		ADD_OBJECT(PhysicalMaterial, TerrainPhysMaterialOverride, 656)
		ADD_BOOL(bShowWireframe, 652, 0x8000)
		ADD_BOOL(bUseWorldOriginTextureUVs, 652, 0x4000)
		ADD_BOOL(bShowingCollision, 652, 0x2000)
		ADD_BOOL(bHeightmapLocked, 652, 0x1000)
		ADD_BOOL(bLocked, 652, 0x800)
		ADD_BOOL(bMorphingGradientsEnabled, 652, 0x400)
		ADD_BOOL(bMorphingEnabled, 652, 0x200)
		ADD_BOOL(bAcceptsDynamicLights, 652, 0x100)
		ADD_BOOL(bAllowRigidBodyUnderneath, 652, 0x80)
		ADD_BOOL(bBlockRigidBody, 652, 0x40)
		ADD_BOOL(bEnableSpecular, 652, 0x20)
		ADD_BOOL(bCastDynamicShadow, 652, 0x10)
		ADD_BOOL(bForceDirectLightMap, 652, 0x8)
		ADD_BOOL(bCastShadow, 652, 0x4)
		ADD_BOOL(bBilinearFilterLightmapGeneration, 652, 0x2)
		ADD_BOOL(bIsOverridingLightResolution, 652, 0x1)
		ADD_STRUCT(int, StaticLightingResolution, 648)
		ADD_STRUCT(int, MaxComponentSize, 644)
		ADD_STRUCT(int, NumPatchesY, 640)
		ADD_STRUCT(int, NumPatchesX, 636)
		ADD_STRUCT(int, NumVerticesY, 632)
		ADD_STRUCT(int, NumVerticesX, 628)
		ADD_STRUCT(Terrain__CachedTerrainMaterialArray, CachedTerrainMaterials, 604)
		ADD_STRUCT(int, CollisionTesselationLevel, 600)
		ADD_STRUCT(float, TessellationCheckDistance, 596)
		ADD_STRUCT(float, TesselationDistanceScale, 592)
		ADD_STRUCT(int, MinTessellationLevel, 588)
		ADD_STRUCT(int, MaxTesselationLevel, 584)
		ADD_STRUCT(int, NumSectionsY, 556)
		ADD_STRUCT(int, NumSectionsX, 552)
		ADD_STRUCT(int, NormalMapLayer, 512)
		void CalcLayerBounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27866);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
