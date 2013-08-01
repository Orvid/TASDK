#pragma once
namespace UnrealScript
{
	enum PrimitiveComponent__GJKResult : byte
	{
		GJK_Intersect = 0,
		GJK_NoIntersection = 1,
		GJK_Fail = 2,
		GJK_MAX = 3,
	};
}
