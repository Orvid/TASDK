#pragma once
namespace UnrealScript
{
	struct SkeletalMesh__BoneMirrorInfo;
}
#include "Core.Object.EAxis.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__BoneMirrorInfo
	{
	public:
		ADD_STRUCT(int, SourceIndex, 0)
		ADD_STRUCT(Object__EAxis, BoneFlipAxis, 4)
	};
}
#undef ADD_STRUCT
