#pragma once
namespace UnrealScript
{
	struct AnimTree__PreviewSkelMeshStruct;
}
#include "Engine.MorphTargetSet.h"
#include "Engine.SkeletalMesh.h"
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
	struct AnimTree__PreviewSkelMeshStruct
	{
	public:
		ADD_STRUCT(ScriptArray<class MorphTargetSet*>, PreviewMorphSets, 12)
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 8)
		ADD_STRUCT(ScriptName, DisplayName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
