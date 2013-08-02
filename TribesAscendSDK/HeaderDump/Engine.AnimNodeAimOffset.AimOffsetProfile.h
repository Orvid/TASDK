#pragma once
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimOffsetProfile;
}
#include "Core.Object.Vector2D.h"
#include "Engine.AnimNodeAimOffset.AimComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimOffsetProfile
	{
	public:
		ADD_STRUCT(ScriptArray<AnimNodeAimOffset__AimComponent>, AimComponents, 24)
		ADD_STRUCT(ScriptName, AnimName_RD, 100)
		ADD_STRUCT(ScriptName, AnimName_RC, 92)
		ADD_STRUCT(ScriptName, AnimName_RU, 84)
		ADD_STRUCT(ScriptName, AnimName_CD, 76)
		ADD_STRUCT(ScriptName, AnimName_CC, 68)
		ADD_STRUCT(ScriptName, AnimName_CU, 60)
		ADD_STRUCT(ScriptName, AnimName_LD, 52)
		ADD_STRUCT(ScriptName, AnimName_LC, 44)
		ADD_STRUCT(ScriptName, AnimName_LU, 36)
		ADD_STRUCT(Object__Vector2D, VerticalRange, 16)
		ADD_STRUCT(Object__Vector2D, HorizontalRange, 8)
		ADD_STRUCT(ScriptName, ProfileName, 0)
	};
}
#undef ADD_STRUCT
