#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameThirdPersonCameraMode__ViewOffsetData
	{
	public:
		ADD_STRUCT(Vector, OffsetLow, 24)
		ADD_STRUCT(Vector, OffsetMid, 12)
		ADD_STRUCT(Vector, OffsetHigh, 0)
	};
}
#undef ADD_STRUCT
