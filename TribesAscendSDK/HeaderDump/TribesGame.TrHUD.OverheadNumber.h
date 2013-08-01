#pragma once
#include "Core.Object.Color.h"
#include "Core.Object.Vector4.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrHUD__OverheadNumber
	{
	public:
		ADD_STRUCT(float, CurrentScale, 36)
		ADD_STRUCT(Object__Color, CurrentColor, 32)
		ADD_STRUCT(Object__Vector4, WorldSpaceLocation, 16)
		ADD_STRUCT(float, RemainingTime, 4)
		ADD_STRUCT(int, NumberValue, 0)
	};
}
#undef ADD_STRUCT
