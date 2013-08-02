#pragma once
namespace UnrealScript
{
	struct ProcBuilding__PBEdgeInfo;
}
#include "Engine.ProcBuilding.EScopeEdge.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuilding__PBEdgeInfo
	{
	public:
		ADD_STRUCT(Vector, EdgeEnd, 0)
		ADD_STRUCT(Vector, EdgeStart, 12)
		ADD_STRUCT(int, ScopeAIndex, 24)
		ADD_STRUCT(ProcBuilding__EScopeEdge, ScopeAEdge, 28)
		ADD_STRUCT(int, ScopeBIndex, 32)
		ADD_STRUCT(ProcBuilding__EScopeEdge, ScopeBEdge, 36)
		ADD_STRUCT(float, EdgeAngle, 40)
	};
}
#undef ADD_STRUCT
