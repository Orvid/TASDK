#pragma once
#include "Engine__UIDataStore_Remote.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlinePlayerData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlinePlayerData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlinePlayerData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlinePlayerData : public UIDataStore_Remote
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		ADD_OBJECT(UIDataProvider_OnlinePartyChatList, PartyChatProvider)
		ADD_VAR(::StrProperty, PartyChatProviderClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AchievementsProviderClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendMessagesProviderClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendsProviderClassName, 0xFFFFFFFF)
		ADD_OBJECT(UIDataProvider_PlayerAchievements, AchievementsProvider)
		ADD_OBJECT(UIDataProvider_OnlineFriendMessages, FriendMessagesProvider)
		ADD_OBJECT(UIDataProvider_OnlinePlayerStorage, StorageProvider)
		ADD_VAR(::StrProperty, PlayerStorageClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileSettingsClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerNick, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerControllerId, 0xFFFFFFFF)
		ADD_OBJECT(UIDataProvider_OnlineFriends, FriendsProvider)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
