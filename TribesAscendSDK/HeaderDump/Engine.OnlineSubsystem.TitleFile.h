#pragma once
#include "Engine.OnlineSubsystem.EOnlineEnumerationReadState.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__TitleFile
	{
	public:
		ADD_STRUCT(ScriptString*, Filename, 0)
		ADD_STRUCT(OnlineSubsystem__EOnlineEnumerationReadState, AsyncState, 12)
		ADD_STRUCT(ScriptArray<byte>, Data, 16)
	};
}
#undef ADD_STRUCT
