#pragma once
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages;
}
#include "Core.Object.Pointer.h"
#include "Engine.LocalPlayer.h"
#include "Engine.OnlineSubsystem.OnlineFriendMessage.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem__OnlineFriendMessage>, Messages, 96)
		ADD_STRUCT(ScriptString*, LastInviteFrom, 168)
		ADD_STRUCT(ScriptString*, MessageCol, 156)
		ADD_STRUCT(ScriptString*, bWasDeniedCol, 144)
		ADD_STRUCT(ScriptString*, bWasAcceptedCol, 132)
		ADD_STRUCT(ScriptString*, bIsFriendInviteCol, 120)
		ADD_STRUCT(ScriptString*, SendingPlayerNameCol, 108)
		ADD_STRUCT(Object__Pointer, VfTable_IUIListElementCellProvider, 92)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28164);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28168);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadMessages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28171);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem__UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28174);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem__UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem__UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28179);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem__UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28184);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* InviterName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28186);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
