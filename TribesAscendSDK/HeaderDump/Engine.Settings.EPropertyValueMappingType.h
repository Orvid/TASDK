#pragma once
namespace UnrealScript
{
	enum Settings__EPropertyValueMappingType : byte
	{
		PVMT_RawValue = 0,
		PVMT_PredefinedValues = 1,
		PVMT_Ranged = 2,
		PVMT_IdMapped = 3,
		PVMT_MAX = 4,
	};
}
