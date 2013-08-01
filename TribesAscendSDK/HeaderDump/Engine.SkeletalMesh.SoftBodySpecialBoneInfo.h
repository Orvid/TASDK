#pragma once
#include "Engine.SkeletalMesh.SoftBodyBoneType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__SoftBodySpecialBoneInfo
	{
	public:
		ADD_STRUCT(ScriptArray<int>, AttachedVertexIndices, 12)
		ADD_STRUCT(SkeletalMesh__SoftBodyBoneType, BoneType, 8)
		ADD_STRUCT(ScriptName, BoneName, 0)
	};
}
#undef ADD_STRUCT
