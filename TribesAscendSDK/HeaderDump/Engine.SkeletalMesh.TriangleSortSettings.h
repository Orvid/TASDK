#pragma once
namespace UnrealScript
{
	struct SkeletalMesh__TriangleSortSettings;
}
#include "Engine.SkeletalMesh.TriangleSortAxis.h"
#include "Engine.SkeletalMesh.TriangleSortOption.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__TriangleSortSettings
	{
	public:
		ADD_STRUCT(SkeletalMesh__TriangleSortOption, TriangleSorting, 0)
		ADD_STRUCT(SkeletalMesh__TriangleSortAxis, CustomLeftRightAxis, 1)
		ADD_STRUCT(ScriptName, CustomLeftRightBoneName, 4)
	};
}
#undef ADD_STRUCT
