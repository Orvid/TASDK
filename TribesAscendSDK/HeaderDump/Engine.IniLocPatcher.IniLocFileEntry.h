#pragma once
namespace UnrealScript
{
	struct IniLocPatcher__IniLocFileEntry;
}
#include "Engine.OnlineSubsystem.EOnlineEnumerationReadState.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct IniLocPatcher__IniLocFileEntry
	{
	public:
		ADD_STRUCT(OnlineSubsystem__EOnlineEnumerationReadState, ReadState, 12)
		ADD_STRUCT(ScriptString*, Filename, 0)
	};
}
#undef ADD_STRUCT
