#pragma once
namespace UnrealScript
{
	struct ProcBuilding__PBMaterialParam;
}
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuilding__PBMaterialParam
	{
	public:
		ADD_STRUCT(ScriptName, ParamName, 0)
		ADD_STRUCT(Object__LinearColor, Color, 8)
	};
}
#undef ADD_STRUCT
