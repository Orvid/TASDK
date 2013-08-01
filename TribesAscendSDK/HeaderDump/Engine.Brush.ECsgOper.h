#pragma once
namespace UnrealScript
{
	enum Brush__ECsgOper : byte
	{
		CSG_Active = 0,
		CSG_Add = 1,
		CSG_Subtract = 2,
		CSG_Intersect = 3,
		CSG_Deintersect = 4,
		CSG_MAX = 5,
	};
}
