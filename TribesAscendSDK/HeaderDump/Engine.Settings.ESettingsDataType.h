#pragma once
namespace UnrealScript
{
	enum Settings__ESettingsDataType : byte
	{
		SDT_Empty = 0,
		SDT_Int32 = 1,
		SDT_Int64 = 2,
		SDT_Double = 3,
		SDT_String = 4,
		SDT_Float = 5,
		SDT_Blob = 6,
		SDT_DateTime = 7,
		SDT_MAX = 8,
	};
}
