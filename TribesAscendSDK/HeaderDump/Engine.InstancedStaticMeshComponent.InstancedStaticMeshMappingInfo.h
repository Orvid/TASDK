#pragma once
namespace UnrealScript
{
	struct InstancedStaticMeshComponent__InstancedStaticMeshMappingInfo;
}
#include "Core.Object.Pointer.h"
#include "Engine.ShadowMap2D.h"
#include "Engine.Texture2D.h"
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
	struct InstancedStaticMeshComponent__InstancedStaticMeshMappingInfo
	{
	public:
		ADD_OBJECT(ShadowMap2D, ShadowmapTexture, 12)
		ADD_OBJECT(Texture2D, LightmapTexture, 8)
		ADD_STRUCT(Object__Pointer, LightMap, 4)
		ADD_STRUCT(Object__Pointer, Mapping, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
