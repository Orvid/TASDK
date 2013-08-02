#pragma once
namespace UnrealScript
{
	struct Object__MultiMap_Mirror;
}
#include "Core.Object.Set_Mirror.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__MultiMap_Mirror
	{
	public:
		ADD_STRUCT(Object__Set_Mirror, Pairs, 0)
	};
}
#undef ADD_STRUCT
