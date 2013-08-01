#pragma once
namespace UnrealScript
{
	enum MeshBeacon__EMeshBeaconPacketType : byte
	{
		MB_Packet_UnknownType = 0,
		MB_Packet_ClientNewConnectionRequest = 1,
		MB_Packet_ClientBeginBandwidthTest = 2,
		MB_Packet_ClientCreateNewSessionResponse = 3,
		MB_Packet_HostNewConnectionResponse = 4,
		MB_Packet_HostBandwidthTestRequest = 5,
		MB_Packet_HostCompletedBandwidthTest = 6,
		MB_Packet_HostTravelRequest = 7,
		MB_Packet_HostCreateNewSessionRequest = 8,
		MB_Packet_DummyData = 9,
		MB_Packet_Heartbeat = 10,
		MB_Packet_MAX = 11,
	};
}
