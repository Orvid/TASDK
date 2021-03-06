#pragma once
namespace UnrealScript
{
	class Note;
}
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Note : public Actor
	{
	public:
		ADD_STRUCT(ScriptString*, Text, 476)
	};
}
#undef ADD_STRUCT
