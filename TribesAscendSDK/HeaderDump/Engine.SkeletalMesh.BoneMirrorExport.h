#pragma once
#include "Core.Object.EAxis.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__BoneMirrorExport
	{
	public:
		ADD_STRUCT(ScriptName, BoneName, 0)
		ADD_STRUCT(ScriptName, SourceBoneName, 8)
		ADD_STRUCT(Object__EAxis, BoneFlipAxis, 16)
	};
}
#undef ADD_STRUCT
