#pragma once
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__BitArray_Mirror
	{
	public:
		ADD_STRUCT(Object__Pointer, IndirectData, 0)
		ADD_STRUCT(int, InlineData, 4)
		ADD_STRUCT(int, NumBits, 20)
		ADD_STRUCT(int, MaxBits, 24)
	};
}
#undef ADD_STRUCT
