#pragma once
namespace UnrealScript
{
	enum TcpLink__ELinkState : byte
	{
		STATE_Initialized = 0,
		STATE_Ready = 1,
		STATE_Listening = 2,
		STATE_Connecting = 3,
		STATE_Connected = 4,
		STATE_ListenClosePending = 5,
		STATE_ConnectClosePending = 6,
		STATE_ListenClosing = 7,
		STATE_ConnectClosing = 8,
		STATE_MAX = 9,
	};
}
