#pragma once
namespace UnrealScript
{
	struct LocalPlayer__SynchronizedActorVisibilityHistory;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct LocalPlayer__SynchronizedActorVisibilityHistory
	{
	public:
		ADD_STRUCT(Object__Pointer, CriticalSection, 4)
		ADD_STRUCT(Object__Pointer, State, 0)
	};
}
#undef ADD_STRUCT
