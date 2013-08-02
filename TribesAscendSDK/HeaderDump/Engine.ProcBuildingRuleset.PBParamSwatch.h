#pragma once
namespace UnrealScript
{
	struct ProcBuildingRuleset__PBParamSwatch;
}
#include "Engine.ProcBuilding.PBMaterialParam.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuildingRuleset__PBParamSwatch
	{
	public:
		ADD_STRUCT(ScriptName, SwatchName, 0)
		ADD_STRUCT(ScriptArray<ProcBuilding__PBMaterialParam>, Params, 8)
	};
}
#undef ADD_STRUCT
