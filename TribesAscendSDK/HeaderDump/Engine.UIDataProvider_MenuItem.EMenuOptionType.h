#pragma once
namespace UnrealScript
{
	enum UIDataProvider_MenuItem__EMenuOptionType : byte
	{
		MENUOT_ComboReadOnly = 0,
		MENUOT_ComboNumeric = 1,
		MENUOT_CheckBox = 2,
		MENUOT_Slider = 3,
		MENUOT_Spinner = 4,
		MENUOT_EditBox = 5,
		MENUOT_CollectionCheckBox = 6,
		MENUOT_CollapsingList = 7,
		MENUOT_MAX = 8,
	};
}
