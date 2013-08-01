#pragma once
namespace UnrealScript
{
	enum TgSupportCommands__GC_STEAM_TXN_TYPES : byte
	{
		GC_STT_INVALID = 0,
		GC_STT_GETUSERINFO = 1,
		GC_STT_INIT = 2,
		GC_STT_FINALIZE = 3,
		GC_STT_DECLINE = 4,
		GC_STT_MAX = 5,
	};
}
