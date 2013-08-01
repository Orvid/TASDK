#pragma once
namespace UnrealScript
{
	enum SkeletalMesh__TriangleSortOption : byte
	{
		TRISORT_None = 0,
		TRISORT_CenterRadialDistance = 1,
		TRISORT_Random = 2,
		TRISORT_Tootle = 3,
		TRISORT_MergeContiguous = 4,
		TRISORT_Custom = 5,
		TRISORT_CustomLeftRight = 6,
		TRISORT_MAX = 7,
	};
}
