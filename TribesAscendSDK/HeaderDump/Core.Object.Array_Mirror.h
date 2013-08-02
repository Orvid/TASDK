#pragma once
namespace UnrealScript
{
	struct Object__Array_Mirror;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Array_Mirror
	{
	public:
		ADD_STRUCT(Object__Pointer, Data, 0)
		ADD_STRUCT(int, ArrayNum, 4)
		ADD_STRUCT(int, ArrayMax, 8)
	};
}
#undef ADD_STRUCT
