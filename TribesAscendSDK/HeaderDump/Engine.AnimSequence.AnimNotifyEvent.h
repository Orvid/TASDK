#pragma once
namespace UnrealScript
{
	struct AnimSequence__AnimNotifyEvent;
}
#include "Engine.AnimNotify.h"
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
	struct AnimSequence__AnimNotifyEvent
	{
	public:
		ADD_STRUCT(float, Time, 0)
		ADD_OBJECT(AnimNotify, Notify, 4)
		ADD_STRUCT(ScriptName, Comment, 8)
		ADD_STRUCT(float, Duration, 16)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
