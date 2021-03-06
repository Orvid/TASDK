#pragma once
namespace UnrealScript
{
	class SeqEvent_ParticleEvent;
}
#include "Engine.SeqEvent_ParticleEvent.EParticleEventOutputType.h"
#include "Engine.SequenceEvent.h"
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
	class SeqEvent_ParticleEvent : public SequenceEvent
	{
	public:
		typedef SeqEvent_ParticleEvent__EParticleEventOutputType EParticleEventOutputType;
		ADD_BOOL(UseRelfectedImpactVector, 304, 0x1)
		ADD_STRUCT(Vector, EventNormal, 292)
		ADD_STRUCT(float, EventParticleTime, 288)
		ADD_STRUCT(Vector, EventVelocity, 276)
		ADD_STRUCT(float, EventEmitterTime, 272)
		ADD_STRUCT(Vector, EventPosition, 260)
		ADD_STRUCT(SeqEvent_ParticleEvent__EParticleEventOutputType, EventType, 256)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26138);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
