#pragma once
namespace UnrealScript
{
	enum CoverGroup__ECoverGroupFillAction : byte
	{
		CGFA_Overwrite = 0,
		CGFA_Add = 1,
		CGFA_Remove = 2,
		CGFA_Clear = 3,
		CGFA_Cylinder = 4,
		CGFA_MAX = 5,
	};
}
