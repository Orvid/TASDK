#pragma once
namespace UnrealScript
{
	struct SkeletalMesh__SkeletalMeshLODInfo;
}
#include "Engine.SkeletalMesh.TriangleSortOption.h"
#include "Engine.SkeletalMesh.TriangleSortSettings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__SkeletalMeshLODInfo
	{
	public:
		ADD_STRUCT(float, DisplayFactor, 0)
		ADD_STRUCT(float, LODHysteresis, 4)
		ADD_STRUCT(ScriptArray<int>, LODMaterialMap, 8)
		ADD_STRUCT(ScriptArray<bool>, bEnableShadowCasting, 20)
		ADD_STRUCT(ScriptArray<SkeletalMesh__TriangleSortOption>, TriangleSorting, 32)
		ADD_STRUCT(ScriptArray<SkeletalMesh__TriangleSortSettings>, TriangleSortSettings, 44)
	};
}
#undef ADD_STRUCT
