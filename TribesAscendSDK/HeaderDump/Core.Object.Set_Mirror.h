#pragma once
#include "Core.Object.SparseArray_Mirror.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Set_Mirror
	{
	public:
		ADD_STRUCT(Object__SparseArray_Mirror, Elements, 0)
		ADD_STRUCT(Object__Pointer, Hash, 48)
		ADD_STRUCT(int, InlineHash, 52)
		ADD_STRUCT(int, HashSize, 56)
	};
}
#undef ADD_STRUCT
