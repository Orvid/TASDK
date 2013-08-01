#pragma once
#include "OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.EMuteType.h"
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
	struct OnlineVoiceInterfaceMcts__LocalTalkerMcts
	{
	public:
		ADD_STRUCT(OnlineVoiceInterfaceMcts__EMuteType, MuteType, 4)
		ADD_BOOL(bIsRegistered, 0, 0x20)
		ADD_BOOL(bIsTalking, 0, 0x10)
		ADD_BOOL(bWasTalking, 0, 0x8)
		ADD_BOOL(bIsRecognizingSpeech, 0, 0x4)
		ADD_BOOL(bHasNetworkedVoice, 0, 0x2)
		ADD_BOOL(bHasVoice, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
