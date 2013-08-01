#pragma once
#include "Engine.ShadowMap2D.h"
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct StaticMeshComponent__StaticMeshComponentLODInfo
	{
	public:
		ADD_STRUCT(ScriptArray<class ShadowMap2D*>, ShadowMaps, 0)
		ADD_STRUCT(ScriptArray<class Object*>, ShadowVertexBuffers, 12)
		ADD_STRUCT(ScriptArray<Vector>, VertexColorPositions, 32)
		ADD_STRUCT(Object__Pointer, OverrideVertexColors, 28)
		ADD_STRUCT(Object__Pointer, LightMap, 24)
	};
}
#undef ADD_STRUCT
