#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.InstancedStaticMeshComponent.InstancedStaticMeshInstanceData.h"
#include "Engine.InstancedStaticMeshComponent.InstancedStaticMeshMappingInfo.h"
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
	class InstancedStaticMeshComponent : public StaticMeshComponent
	{
	public:
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent__InstancedStaticMeshInstanceData>, PerInstanceData, 608)
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent__InstancedStaticMeshInstanceData>, PerInstanceSMData, 620)
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent__InstancedStaticMeshMappingInfo>, CachedMappings, 640)
		ADD_STRUCT(int, InstancingRandomSeed, 652)
		ADD_STRUCT(int, ComponentJoinKey, 636)
		ADD_STRUCT(int, NumPendingLightmaps, 632)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
