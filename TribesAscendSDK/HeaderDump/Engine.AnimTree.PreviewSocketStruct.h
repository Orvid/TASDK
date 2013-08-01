#pragma once
#include "Engine.StaticMesh.h"
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
	struct AnimTree__PreviewSocketStruct
	{
	public:
		ADD_OBJECT(StaticMesh, PreviewStaticMesh, 20)
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 16)
		ADD_STRUCT(ScriptName, SocketName, 8)
		ADD_STRUCT(ScriptName, DisplayName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
