#pragma once
namespace UnrealScript
{
	enum PlayerController__EProgressMessageType : byte
	{
		PMT_Clear = 0,
		PMT_Information = 1,
		PMT_AdminMessage = 2,
		PMT_DownloadProgress = 3,
		PMT_ConnectionFailure = 4,
		PMT_PeerConnectionFailure = 5,
		PMT_PeerHostMigrationFailure = 6,
		PMT_SocketFailure = 7,
		PMT_MAX = 8,
	};
}
