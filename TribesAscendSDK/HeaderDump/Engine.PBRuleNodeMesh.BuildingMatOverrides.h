#pragma once
namespace UnrealScript
{
	struct PBRuleNodeMesh__BuildingMatOverrides;
}
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PBRuleNodeMesh__BuildingMatOverrides
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, MaterialOptions, 0)
	};
}
#undef ADD_STRUCT
