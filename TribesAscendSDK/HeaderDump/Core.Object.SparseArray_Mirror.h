#pragma once
namespace UnrealScript
{
	struct Object__SparseArray_Mirror;
}
#include "Core.Object.BitArray_Mirror.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__SparseArray_Mirror
	{
	public:
		ADD_STRUCT(ScriptArray<int>, Elements, 0)
		ADD_STRUCT(Object__BitArray_Mirror, AllocationFlags, 12)
		ADD_STRUCT(int, FirstFreeIndex, 40)
		ADD_STRUCT(int, NumFreeIndices, 44)
	};
}
#undef ADD_STRUCT
