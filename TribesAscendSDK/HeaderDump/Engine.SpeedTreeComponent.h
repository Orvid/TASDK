#pragma once
#include "Engine.Texture2D.h"
#include "Engine.SpeedTreeComponent.ESpeedTreeMeshType.h"
#include "Engine.SpeedTreeComponent.SpeedTreeStaticLight.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#include "Engine.SpeedTree.h"
#include "Engine.MaterialInterface.h"
#include "Core.Object.Matrix.h"
#include "Engine.EngineTypes.LightMapRef.h"
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
	class SpeedTreeComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<SpeedTreeComponent__SpeedTreeStaticLight>, StaticLights, 544)
		ADD_STRUCT(EngineTypes__LightmassPrimitiveSettings, LightmassSettings, 640)
		ADD_STRUCT(Object__Matrix, RotationOnlyMatrix, 576)
		ADD_STRUCT(EngineTypes__LightMapRef, BillboardLightMap, 572)
		ADD_STRUCT(EngineTypes__LightMapRef, LeafCardLightMap, 568)
		ADD_STRUCT(EngineTypes__LightMapRef, LeafMeshLightMap, 564)
		ADD_STRUCT(EngineTypes__LightMapRef, FrondLightMap, 560)
		ADD_STRUCT(EngineTypes__LightMapRef, BranchLightMap, 556)
		ADD_OBJECT(Texture2D, SpeedTreeIcon, 540)
		ADD_OBJECT(MaterialInterface, BillboardMaterial, 536)
		ADD_OBJECT(MaterialInterface, LeafMeshMaterial, 532)
		ADD_OBJECT(MaterialInterface, LeafCardMaterial, 528)
		ADD_OBJECT(MaterialInterface, FrondMaterial, 524)
		ADD_OBJECT(MaterialInterface, Branch2Material, 520)
		ADD_OBJECT(MaterialInterface, Branch1Material, 516)
		ADD_STRUCT(float, LodLevelOverride, 512)
		ADD_STRUCT(float, LodBillboardEnd, 508)
		ADD_STRUCT(float, LodBillboardStart, 504)
		ADD_STRUCT(float, Lod3DEnd, 500)
		ADD_STRUCT(float, Lod3DStart, 496)
		ADD_BOOL(bUseBillboards, 492, 0x10)
		ADD_BOOL(bUseFronds, 492, 0x8)
		ADD_BOOL(bUseBranches, 492, 0x4)
		ADD_BOOL(bUseLeafMeshes, 492, 0x2)
		ADD_BOOL(bUseLeafCards, 492, 0x1)
		ADD_OBJECT(SpeedTree, SpeedTree, 488)
		class MaterialInterface* GetMaterial(SpeedTreeComponent__ESpeedTreeMeshType MeshType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27073);
			byte params[5] = { NULL };
			*(SpeedTreeComponent__ESpeedTreeMeshType*)params = MeshType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		void SetMaterial(SpeedTreeComponent__ESpeedTreeMeshType MeshType, class MaterialInterface* Material)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27076);
			byte params[5] = { NULL };
			*(SpeedTreeComponent__ESpeedTreeMeshType*)params = MeshType;
			*(class MaterialInterface**)&params[4] = Material;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
