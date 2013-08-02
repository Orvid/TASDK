#pragma once
namespace UnrealScript
{
	class PBRuleNodeEdgeAngle;
}
#include "Engine.PBRuleNodeBase.h"
#include "Engine.PBRuleNodeEdgeAngle.EProcBuildingEdge.h"
#include "Engine.PBRuleNodeEdgeAngle.RBEdgeAngleInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeEdgeAngle : public PBRuleNodeBase
	{
	public:
		typedef PBRuleNodeEdgeAngle__EProcBuildingEdge EProcBuildingEdge;
		typedef PBRuleNodeEdgeAngle__RBEdgeAngleInfo RBEdgeAngleInfo;
		ADD_STRUCT(ScriptArray<PBRuleNodeEdgeAngle__RBEdgeAngleInfo>, Angles, 108)
		ADD_STRUCT(PBRuleNodeEdgeAngle__EProcBuildingEdge, Edge, 104)
	};
}
#undef ADD_STRUCT
