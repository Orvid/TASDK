#pragma once
namespace UnrealScript
{
	struct Engine__StatColorMapEntry;
}
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Engine__StatColorMapEntry
	{
	public:
		ADD_STRUCT(Object__Color, Out, 4)
		ADD_STRUCT(float, In, 0)
	};
}
#undef ADD_STRUCT
