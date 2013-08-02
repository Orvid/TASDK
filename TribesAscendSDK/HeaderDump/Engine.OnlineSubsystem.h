#pragma once
namespace UnrealScript
{
	class OnlineSubsystem;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.IniLocPatcher.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.OnlineSubsystem.AchievementDetails.h"
#include "Engine.OnlineSubsystem.CommunityContentFile.h"
#include "Engine.OnlineSubsystem.CommunityContentMetadata.h"
#include "Engine.OnlineSubsystem.EFeaturePrivilegeLevel.h"
#include "Engine.OnlineSubsystem.ELanBeaconState.h"
#include "Engine.OnlineSubsystem.ELoginStatus.h"
#include "Engine.OnlineSubsystem.ENATType.h"
#include "Engine.OnlineSubsystem.ENetworkNotificationPosition.h"
#include "Engine.OnlineSubsystem.EOnlineAccountCreateStatus.h"
#include "Engine.OnlineSubsystem.EOnlineContentType.h"
#include "Engine.OnlineSubsystem.EOnlineEnumerationReadState.h"
#include "Engine.OnlineSubsystem.EOnlineFriendState.h"
#include "Engine.OnlineSubsystem.EOnlineGameState.h"
#include "Engine.OnlineSubsystem.EOnlineNewsType.h"
#include "Engine.OnlineSubsystem.EOnlineServerConnectionStatus.h"
#include "Engine.OnlineSubsystem.FriendsQuery.h"
#include "Engine.OnlineSubsystem.LocalTalker.h"
#include "Engine.OnlineSubsystem.NamedInterface.h"
#include "Engine.OnlineSubsystem.NamedInterfaceDef.h"
#include "Engine.OnlineSubsystem.NamedSession.h"
#include "Engine.OnlineSubsystem.OnlineArbitrationRegistrant.h"
#include "Engine.OnlineSubsystem.OnlineContent.h"
#include "Engine.OnlineSubsystem.OnlineFriend.h"
#include "Engine.OnlineSubsystem.OnlineFriendMessage.h"
#include "Engine.OnlineSubsystem.OnlinePartyMember.h"
#include "Engine.OnlineSubsystem.OnlinePlayerScore.h"
#include "Engine.OnlineSubsystem.OnlineRegistrant.h"
#include "Engine.OnlineSubsystem.RemoteTalker.h"
#include "Engine.OnlineSubsystem.SpeechRecognizedWord.h"
#include "Engine.OnlineSubsystem.TitleFile.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
		typedef OnlineSubsystem__EOnlineNewsType EOnlineNewsType;
		typedef OnlineSubsystem__ENATType ENATType;
		typedef OnlineSubsystem__EOnlineServerConnectionStatus EOnlineServerConnectionStatus;
		typedef OnlineSubsystem__EOnlineEnumerationReadState EOnlineEnumerationReadState;
		typedef OnlineSubsystem__EOnlineGameState EOnlineGameState;
		typedef OnlineSubsystem__EOnlineAccountCreateStatus EOnlineAccountCreateStatus;
		typedef OnlineSubsystem__ELanBeaconState ELanBeaconState;
		typedef OnlineSubsystem__EOnlineContentType EOnlineContentType;
		typedef OnlineSubsystem__EOnlineFriendState EOnlineFriendState;
		typedef OnlineSubsystem__ENetworkNotificationPosition ENetworkNotificationPosition;
		typedef OnlineSubsystem__EFeaturePrivilegeLevel EFeaturePrivilegeLevel;
		typedef OnlineSubsystem__ELoginStatus ELoginStatus;
		typedef OnlineSubsystem__NamedSession NamedSession;
		typedef OnlineSubsystem__OnlineRegistrant OnlineRegistrant;
		typedef OnlineSubsystem__OnlineArbitrationRegistrant OnlineArbitrationRegistrant;
		typedef OnlineSubsystem__UniqueNetId UniqueNetId;
		typedef OnlineSubsystem__NamedInterface NamedInterface;
		typedef OnlineSubsystem__OnlinePartyMember OnlinePartyMember;
		typedef OnlineSubsystem__AchievementDetails AchievementDetails;
		typedef OnlineSubsystem__CommunityContentMetadata CommunityContentMetadata;
		typedef OnlineSubsystem__CommunityContentFile CommunityContentFile;
		typedef OnlineSubsystem__TitleFile TitleFile;
		typedef OnlineSubsystem__NamedInterfaceDef NamedInterfaceDef;
		typedef OnlineSubsystem__OnlineFriendMessage OnlineFriendMessage;
		typedef OnlineSubsystem__RemoteTalker RemoteTalker;
		typedef OnlineSubsystem__LocalTalker LocalTalker;
		typedef OnlineSubsystem__OnlinePlayerScore OnlinePlayerScore;
		typedef OnlineSubsystem__SpeechRecognizedWord SpeechRecognizedWord;
		typedef OnlineSubsystem__OnlineContent OnlineContent;
		typedef OnlineSubsystem__OnlineFriend OnlineFriend;
		typedef OnlineSubsystem__FriendsQuery FriendsQuery;
		ADD_STRUCT(ScriptArray<OnlineSubsystem__NamedSession>, Sessions, 184)
		ADD_STRUCT(Object__Pointer, VfTable_FTickableObject, 60)
		ADD_STRUCT(ScriptArray<OnlineSubsystem__NamedInterface>, NamedInterfaces, 160)
		ADD_STRUCT(ScriptString*, IniLocPatcherClassName, 204)
		ADD_OBJECT(IniLocPatcher, Patcher, 216)
		ADD_STRUCT(ScriptArray<OnlineSubsystem__NamedInterfaceDef>, NamedInterfaceDefs, 172)
		ADD_BOOL(bUseBuildIdOverride, 196, 0x1)
		ADD_STRUCT(int, BuildIdOverride, 200)
		ADD_STRUCT(float, AsyncMinCompletionTime, 220)
		void SetDebugSpewLevel(int DebugSpewLevel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5436);
			byte params[4] = { NULL };
			*(int*)params = DebugSpewLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DumpVoiceRegistration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5437);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpSessionState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5439);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpGameSettings(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5440);
			byte params[4] = { NULL };
			*(class OnlineGameSettings**)params = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumSupportedLogins()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5456);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetBuildUniqueId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5458);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool StringToUniqueNetId(ScriptString* UniqueNetIdString, OnlineSubsystem__UniqueNetId& out_UniqueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5460);
			byte params[24] = { NULL };
			*(ScriptString**)params = UniqueNetIdString;
			*(OnlineSubsystem__UniqueNetId*)&params[12] = out_UniqueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_UniqueId = *(OnlineSubsystem__UniqueNetId*)&params[12];
			return *(bool*)&params[20];
		}
		ScriptString* UniqueNetIdToString(OnlineSubsystem__UniqueNetId& IdToConvert)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5462);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = IdToConvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			IdToConvert = *(OnlineSubsystem__UniqueNetId*)params;
			return *(ScriptString**)&params[8];
		}
		class Object* GetNamedInterface(ScriptName InterfaceName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5466);
			byte params[12] = { NULL };
			*(ScriptName*)params = InterfaceName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[8];
		}
		void SetNamedInterface(ScriptName InterfaceName, class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5469);
			byte params[12] = { NULL };
			*(ScriptName*)params = InterfaceName;
			*(class Object**)&params[8] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetGameChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5476);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetTitleFileInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5481);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPartyChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5486);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetNewsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5491);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetStatsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5496);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetVoiceInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5501);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetContentInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5506);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetGameInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5511);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetSystemInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5516);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPlayerInterfaceEx(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5521);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPlayerInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5526);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetAccountInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5531);
			byte params[8] = { NULL };
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Exit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5536);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PostInit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5541);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5542);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
