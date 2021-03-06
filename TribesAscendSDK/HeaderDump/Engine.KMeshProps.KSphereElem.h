#pragma once
namespace UnrealScript
{
	struct KMeshProps__KSphereElem;
}
#include "Core.Object.Matrix.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct KMeshProps__KSphereElem
	{
	public:
		ADD_BOOL(bPerPolyShape, 68, 0x2)
		ADD_BOOL(bNoRBCollision, 68, 0x1)
		ADD_STRUCT(float, Radius, 64)
		ADD_STRUCT(Object__Matrix, TM, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
