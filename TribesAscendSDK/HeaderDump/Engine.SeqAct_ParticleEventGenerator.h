#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class SeqAct_ParticleEventGenerator : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, EventNames, 240)
		ADD_STRUCT(Vector, EventNormal, 292)
		ADD_STRUCT(Vector, EventVelocity, 280)
		ADD_STRUCT(Vector, EventDirection, 268)
		ADD_STRUCT(Vector, EventLocation, 256)
		ADD_STRUCT(float, EventTime, 252)
		ADD_OBJECT(Actor, Instigator, 236)
		ADD_BOOL(bUseEmitterLocation, 232, 0x2)
		ADD_BOOL(bEnabled, 232, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25801);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
