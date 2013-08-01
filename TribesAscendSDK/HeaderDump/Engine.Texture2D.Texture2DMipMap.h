#pragma once
#include "Core.Object.UntypedBulkData_Mirror.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Texture2D__Texture2DMipMap
	{
	public:
		ADD_STRUCT(int, SizeY, 56)
		ADD_STRUCT(int, SizeX, 52)
		ADD_STRUCT(Object__UntypedBulkData_Mirror, Data, 0)
	};
}
#undef ADD_STRUCT
