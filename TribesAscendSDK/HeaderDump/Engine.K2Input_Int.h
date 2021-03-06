#pragma once
namespace UnrealScript
{
	class K2Input_Int;
}
#include "Engine.K2Input.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2Input_Int : public K2Input
	{
	public:
		ADD_STRUCT(int, DefaultInt, 84)
	};
}
#undef ADD_STRUCT
