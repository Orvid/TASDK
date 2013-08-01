#pragma once
#include "Core.Object.h"
#include "Core.Object.IntPoint.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class BookMark2D : public Object
	{
	public:
		ADD_STRUCT(Object__IntPoint, Location, 64)
		ADD_STRUCT(float, Zoom2D, 60)
	};
}
#undef ADD_STRUCT
