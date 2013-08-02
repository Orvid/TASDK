#pragma once
namespace UnrealScript
{
	struct UDKExplosionLight__LightValues;
}
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKExplosionLight__LightValues
	{
	public:
		ADD_STRUCT(Object__Color, LightColor, 12)
		ADD_STRUCT(float, Brightness, 8)
		ADD_STRUCT(float, Radius, 4)
		ADD_STRUCT(float, StartTime, 0)
	};
}
#undef ADD_STRUCT
