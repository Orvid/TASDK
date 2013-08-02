#pragma once
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimComponent;
}
#include "Engine.AnimNodeAimOffset.AimTransform.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimComponent
	{
	public:
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, RD, 272)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, RC, 240)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, RU, 208)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, CD, 176)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, CC, 144)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, CU, 112)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, LD, 80)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, LC, 48)
		ADD_STRUCT(AnimNodeAimOffset__AimTransform, LU, 16)
		ADD_STRUCT(ScriptName, BoneName, 0)
	};
}
#undef ADD_STRUCT
