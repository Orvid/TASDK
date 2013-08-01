#pragma once
namespace UnrealScript
{
	enum Pawn__EPathSearchType : byte
	{
		PST_Default = 0,
		PST_Breadth = 1,
		PST_NewBestPathTo = 2,
		PST_Constraint = 3,
		PST_MAX = 4,
	};
}
