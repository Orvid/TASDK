#pragma once
namespace UnrealScript
{
	enum TextureFlipBook__TextureFlipBookMethod : byte
	{
		TFBM_UL_ROW = 0,
		TFBM_UL_COL = 1,
		TFBM_UR_ROW = 2,
		TFBM_UR_COL = 3,
		TFBM_LL_ROW = 4,
		TFBM_LL_COL = 5,
		TFBM_LR_ROW = 6,
		TFBM_LR_COL = 7,
		TFBM_RANDOM = 8,
		TFBM_MAX = 9,
	};
}
