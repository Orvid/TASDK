#pragma once
#include "IpDrv.MeshBeaconClient.ClientBandwidthTestData.h"
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestResult.h"
#include "IpDrv.MeshBeacon.h"
#include "IpDrv.ClientBeaconAddressResolver.h"
#include "IpDrv.MeshBeacon.EMeshBeaconBandwidthTestType.h"
#include "IpDrv.MeshBeacon.PlayerMember.h"
#include "IpDrv.MeshBeacon.EMeshBeaconPacketType.h"
#include "IpDrv.MeshBeaconClient.EMeshBeaconClientState.h"
#include "IpDrv.MeshBeaconClient.ClientConnectionRequest.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#include "IpDrv.MeshBeacon.EMeshBeaconConnectionResult.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MeshBeaconClient : public MeshBeacon
	{
	public:
		ADD_BOOL(bUsingRegisteredAddr, 216, 0x1)
		ADD_OBJECT(ClientBeaconAddressResolver, Resolver, 212)
		ADD_OBJECT(ScriptClass, ResolverClass, 208)
		ADD_STRUCT(ScriptString*, ResolverClassName, 196)
		ADD_STRUCT(float, ConnectionRequestElapsedTime, 192)
		ADD_STRUCT(float, ConnectionRequestTimeout, 188)
		ADD_STRUCT(MeshBeacon__EMeshBeaconPacketType, ClientBeaconRequestType, 185)
		ADD_STRUCT(MeshBeaconClient__EMeshBeaconClientState, ClientBeaconState, 184)
		ADD_STRUCT(MeshBeaconClient__ClientBandwidthTestData, CurrentBandwidthTest, 164)
		ADD_STRUCT(MeshBeaconClient__ClientConnectionRequest, ClientPendingRequest, 128)
		ADD_STRUCT(OnlineGameSearch__OnlineGameSearchResult, HostPendingRequest, 120)
		void OnCreateNewSessionRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, ScriptArray<MeshBeacon__PlayerMember>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33194);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			*(ScriptArray<MeshBeacon__PlayerMember>*)&params[12] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<MeshBeacon__PlayerMember>*)&params[12];
		}
		void OnTravelRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33196);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[12];
		}
		void OnReceivedBandwidthTestResults(MeshBeacon__EMeshBeaconBandwidthTestType TestType, MeshBeacon__EMeshBeaconBandwidthTestResult TestResult, MeshBeacon__ConnectionBandwidthStats& BandwidthStats)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33198);
			byte params[14] = { NULL };
			*(MeshBeacon__EMeshBeaconBandwidthTestType*)params = TestType;
			*(MeshBeacon__EMeshBeaconBandwidthTestResult*)&params[1] = TestResult;
			*(MeshBeacon__ConnectionBandwidthStats*)&params[4] = BandwidthStats;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BandwidthStats = *(MeshBeacon__ConnectionBandwidthStats*)&params[4];
		}
		void OnReceivedBandwidthTestRequest(MeshBeacon__EMeshBeaconBandwidthTestType TestType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33200);
			byte params[1] = { NULL };
			*(MeshBeacon__EMeshBeaconBandwidthTestType*)params = TestType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnConnectionRequestResult(MeshBeacon__EMeshBeaconConnectionResult ConnectionResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33202);
			byte params[1] = { NULL };
			*(MeshBeacon__EMeshBeaconConnectionResult*)params = ConnectionResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33230);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequestConnection(OnlineGameSearch__OnlineGameSearchResult& DesiredHost, MeshBeaconClient__ClientConnectionRequest& ClientRequest, bool bRegisterSecureAddress)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33231);
			byte params[52] = { NULL };
			*(OnlineGameSearch__OnlineGameSearchResult*)params = DesiredHost;
			*(MeshBeaconClient__ClientConnectionRequest*)&params[8] = ClientRequest;
			*(bool*)&params[44] = bRegisterSecureAddress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch__OnlineGameSearchResult*)params;
			ClientRequest = *(MeshBeaconClient__ClientConnectionRequest*)&params[8];
			return *(bool*)&params[48];
		}
		bool BeginBandwidthTest(MeshBeacon__EMeshBeaconBandwidthTestType TestType, int TestBufferSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33236);
			byte params[9] = { NULL };
			*(MeshBeacon__EMeshBeaconBandwidthTestType*)params = TestType;
			*(int*)&params[4] = TestBufferSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SendHostNewGameSessionResponse(bool bSuccess, ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33252);
			byte params[21] = { NULL };
			*(bool*)params = bSuccess;
			*(ScriptName*)&params[4] = SessionName;
			*(ScriptClass**)&params[12] = SearchClass;
			params[16] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[16];
			return *(bool*)&params[96];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
