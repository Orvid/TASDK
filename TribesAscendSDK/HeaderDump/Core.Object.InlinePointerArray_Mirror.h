#pragma once
namespace UnrealScript
{
	struct Object__InlinePointerArray_Mirror;
}
#include "Core.Object.Array_Mirror.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__InlinePointerArray_Mirror
	{
	public:
		ADD_STRUCT(Object__Pointer, InlineData, 0)
		ADD_STRUCT(Object__Array_Mirror, SecondaryData, 4)
	};
}
#undef ADD_STRUCT
