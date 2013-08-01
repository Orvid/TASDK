#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
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
namespace UnrealScript
{
	class MeshBeacon : public Object
	{
	public:
		ADD_STRUCT(int, MaxBandwidthHistoryEntries, 116)
		ADD_STRUCT(float, MaxBandwidthTestReceiveTime, 112)
		ADD_STRUCT(float, MaxBandwidthTestSendTime, 108)
		ADD_STRUCT(int, MinBandwidthTestBufferSize, 104)
		ADD_STRUCT(int, MaxBandwidthTestBufferSize, 100)
		ADD_STRUCT(int, SocketReceiveBufferSize, 96)
		ADD_STRUCT(int, SocketSendBufferSize, 92)
		ADD_STRUCT(ScriptName, BeaconName, 84)
		ADD_STRUCT(float, ElapsedHeartbeatTime, 80)
		ADD_STRUCT(float, HeartbeatTimeout, 76)
		ADD_BOOL(bShouldTick, 72, 0x4)
		ADD_BOOL(bWantsDeferredDestroy, 72, 0x2)
		ADD_BOOL(bIsInTick, 72, 0x1)
		ADD_STRUCT(Object__Pointer, Socket, 68)
		ADD_STRUCT(int, MeshBeaconPort, 64)
		ADD_STRUCT(Object__Pointer, VfTable_FTickableObject, 60)
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
