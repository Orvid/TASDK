#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_FollowerActions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_FollowerActions : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, AlreadyFriendText, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TargetOnlineState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TargetPlayerIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TargetPlayer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForFriendActionPopup, 0x1)
		ADD_VAR(::IntProperty, FriendActionPopupIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'RefreshButtons'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
