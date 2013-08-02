#pragma once
namespace UnrealScript
{
	struct Canvas__CanvasUVTri;
}
#include "Core.Object.Vector2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Canvas__CanvasUVTri
	{
	public:
		ADD_STRUCT(Object__Vector2D, V2_UV, 40)
		ADD_STRUCT(Object__Vector2D, V2_Pos, 32)
		ADD_STRUCT(Object__Vector2D, V1_UV, 24)
		ADD_STRUCT(Object__Vector2D, V1_Pos, 16)
		ADD_STRUCT(Object__Vector2D, V0_UV, 8)
		ADD_STRUCT(Object__Vector2D, V0_Pos, 0)
	};
}
#undef ADD_STRUCT
