#pragma once
namespace UnrealScript
{
	enum Engine__ETransitionType : byte
	{
		TT_None = 0,
		TT_Paused = 1,
		TT_Loading = 2,
		TT_Saving = 3,
		TT_Connecting = 4,
		TT_Precaching = 5,
		TT_MAX = 6,
	};
}
