#pragma once
namespace UnrealScript
{
	struct Object__BoneAtom;
}
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__BoneAtom
	{
	public:
		ADD_STRUCT(Object__Quat, Rotation, 0)
		ADD_STRUCT(Vector, Translation, 16)
		ADD_STRUCT(float, Scale, 28)
	};
}
#undef ADD_STRUCT
