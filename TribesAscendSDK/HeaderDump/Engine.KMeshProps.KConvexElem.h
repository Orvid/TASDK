#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Plane.h"
#include "Core.Object.Box.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct KMeshProps__KConvexElem
	{
	public:
		ADD_STRUCT(ScriptArray<Vector>, VertexData, 0)
		ADD_STRUCT(ScriptArray<Object__Plane>, PermutedVertexData, 12)
		ADD_STRUCT(ScriptArray<int>, FaceTriData, 24)
		ADD_STRUCT(ScriptArray<Vector>, EdgeDirections, 36)
		ADD_STRUCT(ScriptArray<Vector>, FaceNormalDirections, 48)
		ADD_STRUCT(ScriptArray<Object__Plane>, FacePlaneData, 60)
		ADD_STRUCT(Object__Box, ElemBox, 72)
	};
}
#undef ADD_STRUCT
