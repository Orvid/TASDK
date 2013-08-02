#pragma once
namespace UnrealScript
{
	struct NavigationHandle__PathStore;
}
#include "Engine.NavigationHandle.EdgePointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct NavigationHandle__PathStore
	{
	public:
		ADD_STRUCT(ScriptArray<NavigationHandle__EdgePointer>, EdgeList, 0)
	};
}
#undef ADD_STRUCT
