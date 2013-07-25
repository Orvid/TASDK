#pragma once
#include "Engine.Texture2D.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.SpeedTree.h"
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpeedTreeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SpeedTreeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SpeedTreeComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpeedTreeComponent : public PrimitiveComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightmassPrimitiveSettings' for the property named 'LightmassSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'RotationOnlyMatrix'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'BillboardLightMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'LeafCardLightMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'LeafMeshLightMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'FrondLightMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'BranchLightMap'!
		ADD_OBJECT(Texture2D, SpeedTreeIcon)
		ADD_OBJECT(MaterialInterface, BillboardMaterial)
		ADD_OBJECT(MaterialInterface, LeafMeshMaterial)
		ADD_OBJECT(MaterialInterface, LeafCardMaterial)
		ADD_OBJECT(MaterialInterface, FrondMaterial)
		ADD_OBJECT(MaterialInterface, Branch2Material)
		ADD_OBJECT(MaterialInterface, Branch1Material)
		ADD_VAR(::FloatProperty, LodLevelOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LodBillboardEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LodBillboardStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Lod3DEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Lod3DStart, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseBillboards, 0x10)
		ADD_VAR(::BoolProperty, bUseFronds, 0x8)
		ADD_VAR(::BoolProperty, bUseBranches, 0x4)
		ADD_VAR(::BoolProperty, bUseLeafMeshes, 0x2)
		ADD_VAR(::BoolProperty, bUseLeafCards, 0x1)
		ADD_OBJECT(SpeedTree, SpeedTree)
		class MaterialInterface* GetMaterial(byte MeshType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpeedTreeComponent.GetMaterial");
			byte* params = (byte*)malloc(5);
			*params = MeshType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetMaterial(byte MeshType, class MaterialInterface* Material)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpeedTreeComponent.SetMaterial");
			byte* params = (byte*)malloc(5);
			*params = MeshType;
			*(class MaterialInterface**)(params + 4) = Material;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT