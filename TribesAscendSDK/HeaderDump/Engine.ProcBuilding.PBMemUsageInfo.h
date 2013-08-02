#pragma once
namespace UnrealScript
{
	struct ProcBuilding__PBMemUsageInfo;
}
#include "Engine.ProcBuilding.h"
#include "Engine.ProcBuildingRuleset.h"
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
	struct ProcBuilding__PBMemUsageInfo
	{
	public:
		ADD_OBJECT(ProcBuilding, Building, 0)
		ADD_OBJECT(ProcBuildingRuleset, Ruleset, 4)
		ADD_STRUCT(int, NumStaticMeshComponent, 8)
		ADD_STRUCT(int, NumInstancedStaticMeshComponents, 12)
		ADD_STRUCT(int, NumInstancedTris, 16)
		ADD_STRUCT(int, LightmapMemBytes, 20)
		ADD_STRUCT(int, ShadowmapMemBytes, 24)
		ADD_STRUCT(int, LODDiffuseMemBytes, 28)
		ADD_STRUCT(int, LODLightingMemBytes, 32)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
