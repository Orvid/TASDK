#pragma once
namespace UnrealScript
{
	class ApexDestructibleAsset;
}
#include "Core.Object.Pointer.h"
#include "Engine.ApexAsset.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleDepthParameters.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleParameters.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleParametersFlag.h"
#include "Engine.FractureMaterial.h"
#include "Engine.MaterialInterface.h"
#include "Engine.PhysicalMaterial.h"
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
	class ApexDestructibleAsset : public ApexAsset
	{
	public:
		typedef ApexDestructibleAsset__NxDestructibleParameters NxDestructibleParameters;
		typedef ApexDestructibleAsset__NxDestructibleDepthParameters NxDestructibleDepthParameters;
		typedef ApexDestructibleAsset__NxDestructibleParametersFlag NxDestructibleParametersFlag;
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 112)
		ADD_STRUCT(ScriptArray<class FractureMaterial*>, FractureMaterials, 124)
		ADD_STRUCT(ApexDestructibleAsset__NxDestructibleParameters, DestructibleParameters, 172)
		ADD_STRUCT(ScriptString*, DustEmitterName, 160)
		ADD_STRUCT(ScriptString*, CrumbleEmitterName, 148)
		ADD_BOOL(bDynamic, 144, 0x2)
		ADD_BOOL(bHasUniqueAssetMaterialNames, 144, 0x1)
		ADD_STRUCT(Object__Pointer, MDestructibleThumbnailComponent, 140)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial, 136)
		ADD_STRUCT(Object__Pointer, MApexAsset, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
