#pragma once
namespace UnrealScript
{
	enum UDKUIDataProvider_MenuOption__EUTOptionType : byte
	{
		UTOT_ComboReadOnly = 0,
		UTOT_ComboNumeric = 1,
		UTOT_CheckBox = 2,
		UTOT_Slider = 3,
		UTOT_Spinner = 4,
		UTOT_EditBox = 5,
		UTOT_CollectionCheckBox = 6,
		UTOT_MAX = 7,
	};
}
