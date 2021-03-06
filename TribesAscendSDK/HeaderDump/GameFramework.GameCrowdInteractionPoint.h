#pragma once
namespace UnrealScript
{
	class GameCrowdInteractionPoint;
}
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
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
namespace UnrealScript
{
	class GameCrowdInteractionPoint : public Actor
	{
	public:
		ADD_BOOL(bIsEnabled, 476, 0x1)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30316);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
