#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Box.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct NavigationPoint__NavigationOctreeObject
	{
	public:
		ADD_STRUCT(byte, OwnerType, 48)
		ADD_OBJECT(Object, Owner, 44)
		ADD_STRUCT(Object__Pointer, OctreeNode, 40)
		ADD_STRUCT(Vector, BoxCenter, 28)
		ADD_STRUCT(Object__Box, BoundingBox, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
