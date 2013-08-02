#pragma once
namespace UnrealScript
{
	struct Object__FColorVertexBuffer_Mirror;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__FColorVertexBuffer_Mirror
	{
	public:
		ADD_STRUCT(Object__Pointer, VfTable, 0)
		ADD_STRUCT(Object__Pointer, VertexData, 4)
		ADD_STRUCT(int, Data, 8)
		ADD_STRUCT(int, Stride, 12)
		ADD_STRUCT(int, NumVertices, 16)
	};
}
#undef ADD_STRUCT
