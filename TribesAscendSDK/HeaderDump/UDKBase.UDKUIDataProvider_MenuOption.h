#pragma once
namespace UnrealScript
{
	class UDKUIDataProvider_MenuOption;
}
#include "Engine.UIRoot.UIRangeData.h"
#include "UDKBase.UDKUIDataProvider_MenuOption.EUTOptionType.h"
#include "UDKBase.UDKUIResourceDataProvider.h"
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
	class UDKUIDataProvider_MenuOption : public UDKUIResourceDataProvider
	{
	public:
		typedef UDKUIDataProvider_MenuOption__EUTOptionType EUTOptionType;
		ADD_STRUCT(ScriptArray<ScriptName>, OptionSet, 156)
		ADD_STRUCT(UIRoot__UIRangeData, RangeData, 220)
		ADD_STRUCT(int, EditBoxMaxLength, 216)
		ADD_BOOL(bOfflineOnly, 212, 0x10)
		ADD_BOOL(bOnlineOnly, 212, 0x8)
		ADD_BOOL(bKeyboardOrMouseOption, 212, 0x4)
		ADD_BOOL(bNumericCombo, 212, 0x2)
		ADD_BOOL(bEditableCombo, 212, 0x1)
		ADD_STRUCT(ScriptString*, Description, 200)
		ADD_STRUCT(ScriptString*, CustomFriendlyName, 188)
		ADD_STRUCT(ScriptName, RequiredGameMode, 180)
		ADD_STRUCT(ScriptString*, DataStoreMarkup, 168)
		ADD_STRUCT(UDKUIDataProvider_MenuOption__EUTOptionType, OptionType, 152)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
