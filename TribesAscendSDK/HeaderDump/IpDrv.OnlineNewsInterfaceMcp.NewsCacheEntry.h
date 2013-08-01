#pragma once
#include "Engine.OnlineSubsystem.EOnlineNewsType.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.EOnlineEnumerationReadState.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineNewsInterfaceMcp__NewsCacheEntry
	{
	public:
		ADD_STRUCT(Object__Pointer, HttpDownloader, 36)
		ADD_BOOL(bIsUnicode, 32, 0x1)
		ADD_STRUCT(float, TimeOut, 28)
		ADD_STRUCT(ScriptString*, NewsItem, 16)
		ADD_STRUCT(OnlineSubsystem__EOnlineNewsType, NewsType, 13)
		ADD_STRUCT(OnlineSubsystem__EOnlineEnumerationReadState, ReadState, 12)
		ADD_STRUCT(ScriptString*, NewsUrl, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT