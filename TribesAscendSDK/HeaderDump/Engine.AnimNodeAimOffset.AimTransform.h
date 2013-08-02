#pragma once
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimTransform;
}
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNodeAimOffset__AimTransform
	{
	public:
		ADD_STRUCT(Vector, Translation, 16)
		ADD_STRUCT(Object__Quat, Quaternion, 0)
	};
}
#undef ADD_STRUCT
