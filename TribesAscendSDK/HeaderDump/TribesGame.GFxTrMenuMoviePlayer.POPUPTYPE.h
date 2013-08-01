#pragma once
namespace UnrealScript
{
	enum GFxTrMenuMoviePlayer__POPUPTYPE : byte
	{
		PUT_NONE = 0,
		PUT_STEAM_INIT = 1,
		PUT_STEAM_FINALIZE = 2,
		PUT_STEAM_DECLINED = 3,
		PUT_STEAM_BADDATA = 4,
		PUT_VIDEO_WARNING = 5,
		PUT_PORTAL_CONFIRM = 6,
		PUT_MAX = 7,
	};
}
