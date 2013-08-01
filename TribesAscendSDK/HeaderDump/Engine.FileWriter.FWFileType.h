#pragma once
namespace UnrealScript
{
	enum FileWriter__FWFileType : byte
	{
		FWFT_Log = 0,
		FWFT_Stats = 1,
		FWFT_HTML = 2,
		FWFT_User = 3,
		FWFT_Debug = 4,
		FWFT_MAX = 5,
	};
}
