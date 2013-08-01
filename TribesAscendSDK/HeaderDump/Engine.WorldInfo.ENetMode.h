#pragma once
namespace UnrealScript
{
	enum WorldInfo__ENetMode : byte
	{
		NM_Standalone = 0,
		NM_DedicatedServer = 1,
		NM_ListenServer = 2,
		NM_Client = 3,
		NM_MAX = 4,
	};
}
