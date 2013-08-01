#pragma once
namespace UnrealScript
{
	enum Scene__ESceneDepthPriorityGroup : byte
	{
		SDPG_UnrealEdBackground = 0,
		SDPG_World = 1,
		SDPG_Foreground = 2,
		SDPG_UnrealEdForeground = 3,
		SDPG_PostProcess = 4,
		SDPG_MAX = 5,
	};
}
