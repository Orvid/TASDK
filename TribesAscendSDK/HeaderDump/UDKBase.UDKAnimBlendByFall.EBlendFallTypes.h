#pragma once
namespace UnrealScript
{
	enum UDKAnimBlendByFall__EBlendFallTypes : byte
	{
		FBT_Up = 0,
		FBT_Down = 1,
		FBT_PreLand = 2,
		FBT_Land = 3,
		FBT_DblJumpUp = 4,
		FBT_DblJumpDown = 5,
		FBT_DblJumpPreLand = 6,
		FBT_DblJumpLand = 7,
		FBT_None = 8,
		FBT_MAX = 9,
	};
}
