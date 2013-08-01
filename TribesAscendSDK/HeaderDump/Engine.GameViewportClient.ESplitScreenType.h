#pragma once
namespace UnrealScript
{
	enum GameViewportClient__ESplitScreenType : byte
	{
		eSST_NONE = 0,
		eSST_2P_HORIZONTAL = 1,
		eSST_2P_VERTICAL = 2,
		eSST_3P_FAVOR_TOP = 3,
		eSST_3P_FAVOR_BOTTOM = 4,
		eSST_4P = 5,
		eSST_MAX = 6,
	};
}
