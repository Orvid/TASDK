#pragma once
namespace UnrealScript
{
	enum OnlineGameSearch__EOnlineGameSearchComparisonType : byte
	{
		OGSCT_Equals = 0,
		OGSCT_NotEquals = 1,
		OGSCT_GreaterThan = 2,
		OGSCT_GreaterThanEquals = 3,
		OGSCT_LessThan = 4,
		OGSCT_LessThanEquals = 5,
		OGSCT_MAX = 6,
	};
}
