#pragma once
namespace UnrealScript
{
	enum GFxUDKFrontEnd_JoinGame__EQueryCompletionAction : byte
	{
		QUERYACTION_None = 0,
		QUERYACTION_Default = 1,
		QUERYACTION_CloseScene = 2,
		QUERYACTION_JoinServer = 3,
		QUERYACTION_RefreshAll = 4,
		QUERYACTION_MAX = 5,
	};
}
