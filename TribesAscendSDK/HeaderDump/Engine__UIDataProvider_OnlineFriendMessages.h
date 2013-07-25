#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlineFriendMessages." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlineFriendMessages." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::StrProperty, LastInviteFrom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MessageCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bWasDeniedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bWasAcceptedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsFriendInviteCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SendingPlayerNameCol, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
