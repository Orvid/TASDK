#pragma once
namespace UnrealScript
{
	struct SkeletalMesh__ClothSpecialBoneInfo;
}
#include "Engine.SkeletalMesh.ClothBoneType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__ClothSpecialBoneInfo
	{
	public:
		ADD_STRUCT(ScriptName, BoneName, 0)
		ADD_STRUCT(SkeletalMesh__ClothBoneType, BoneType, 8)
		ADD_STRUCT(ScriptArray<int>, AttachedVertexIndices, 12)
	};
}
#undef ADD_STRUCT
