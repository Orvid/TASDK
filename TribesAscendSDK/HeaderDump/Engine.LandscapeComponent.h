#pragma once
#include "Core.Object.BoxSphereBounds.h"
#include "Engine.Texture2D.h"
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.LandscapeComponent.WeightmapLayerAllocationInfo.h"
#include "Engine.EngineTypes.LightMapRef.h"
#include "Engine.LandscapeComponent.LandscapeComponentAlphaInfo.h"
#include "Core.Object.Guid.h"
#include "Engine.ShadowMap2D.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.Vector4.h"
#include "Engine.MaterialInstanceConstant.h"
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
	class LandscapeComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<LandscapeComponent__LandscapeComponentAlphaInfo>, EditingAlphaLayerData, 512)
		ADD_STRUCT(ScriptArray<LandscapeComponent__WeightmapLayerAllocationInfo>, WeightmapLayerAllocations, 532)
		ADD_STRUCT(ScriptArray<class Texture2D*>, WeightmapTextures, 544)
		ADD_STRUCT(ScriptArray<class ShadowMap2D*>, ShadowMaps, 672)
		ADD_STRUCT(ScriptArray<Object__Guid>, IrrelevantLights, 684)
		ADD_STRUCT(int, CollisionMipLevel, 704)
		ADD_STRUCT(Object__Pointer, EditToolRenderData, 700)
		ADD_STRUCT(EngineTypes__LightMapRef, LightMap, 696)
		ADD_STRUCT(Object__Guid, LightingGuid, 656)
		ADD_STRUCT(int, StaticLightingResolution, 652)
		ADD_STRUCT(Object__BoxSphereBounds, CachedBoxSphereBounds, 624)
		ADD_OBJECT(Texture2D, HeightmapTexture, 620)
		ADD_STRUCT(Object__Vector2D, LayerUVPan, 612)
		ADD_STRUCT(float, HeightmapSubsectionOffset, 608)
		ADD_STRUCT(Object__Vector4, HeightmapScaleBias, 592)
		ADD_STRUCT(float, WeightmapSubsectionOffset, 576)
		ADD_STRUCT(Object__Vector4, WeightmapScaleBias, 560)
		ADD_STRUCT(ScriptName, EditingAlphaLayerName, 524)
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstance, 508)
		ADD_STRUCT(int, NumSubsections, 504)
		ADD_STRUCT(int, SubsectionSizeQuads, 500)
		ADD_STRUCT(int, ComponentSizeQuads, 496)
		ADD_STRUCT(int, SectionBaseY, 492)
		ADD_STRUCT(int, SectionBaseX, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
