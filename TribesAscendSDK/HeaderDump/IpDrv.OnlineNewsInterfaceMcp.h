#pragma once
namespace UnrealScript
{
	class OnlineNewsInterfaceMcp;
}
#include "Engine.OnlineSubsystem.EOnlineNewsType.h"
#include "IpDrv.MCPBase.h"
#include "IpDrv.OnlineNewsInterfaceMcp.NewsCacheEntry.h"
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
	class OnlineNewsInterfaceMcp : public MCPBase
	{
	public:
		typedef OnlineNewsInterfaceMcp__NewsCacheEntry NewsCacheEntry;
		ADD_STRUCT(ScriptArray<OnlineNewsInterfaceMcp__NewsCacheEntry>, NewsItems, 64)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ReadNewsDelegates, 76)
		ADD_BOOL(bNeedsTicking, 88, 0x1)
		void OnReadNewsCompleted(bool bWasSuccessful, OnlineSubsystem__EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33649);
			byte params[5] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(OnlineSubsystem__EOnlineNewsType*)&params[4] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadNews(byte LocalUserNum, OnlineSubsystem__EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33659);
			byte params[6] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem__EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33665);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadGameNewsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33667);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadGameNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetNews(byte LocalUserNum, OnlineSubsystem__EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33670);
			byte params[14] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem__EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
