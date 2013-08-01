#pragma once
namespace UnrealScript
{
	enum OnlinePlayerStorage__EOnlinePlayerStorageAsyncState : byte
	{
		OPAS_None = 0,
		OPAS_Read = 1,
		OPAS_Write = 2,
		OPAS_MAX = 3,
	};
}
