#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuilding__PBFaceUVInfo
	{
	public:
		ADD_STRUCT(Object__Vector2D, Offset, 0)
		ADD_STRUCT(Object__Vector2D, Size, 8)
	};
}
#undef ADD_STRUCT
