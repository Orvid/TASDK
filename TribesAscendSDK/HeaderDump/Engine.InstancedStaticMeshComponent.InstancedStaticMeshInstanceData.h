#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Matrix.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InstancedStaticMeshComponent__InstancedStaticMeshInstanceData
	{
	public:
		ADD_STRUCT(Object__Vector2D, ShadowmapUVBias, 72)
		ADD_STRUCT(Object__Vector2D, LightmapUVBias, 64)
		ADD_STRUCT(Object__Matrix, Transform, 0)
	};
}
#undef ADD_STRUCT
