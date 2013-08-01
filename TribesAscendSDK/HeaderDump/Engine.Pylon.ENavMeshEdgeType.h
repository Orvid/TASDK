#pragma once
namespace UnrealScript
{
	enum Pylon__ENavMeshEdgeType : byte
	{
		NAVEDGE_Normal = 0,
		NAVEDGE_Mantle = 1,
		NAVEDGE_Coverslip = 2,
		NAVEDGE_SwatTurn = 3,
		NAVEDGE_DropDown = 4,
		NAVEDGE_PathObject = 5,
		NAVEDGE_BackRefDummy = 6,
		NAVEDGE_Jump = 7,
		NAVEDGE_MAX = 8,
	};
}
