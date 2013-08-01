#pragma once
#include "Engine.GameplayEventsHandler.h"
#include "GameFramework.GameStateObject.GameSessionType.h"
#include "Core.Object.Array_Mirror.h"
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
	class GameStateObject : public GameplayEventsHandler
	{
	public:
		ADD_STRUCT(int, MaxRoundNumber, 124)
		ADD_STRUCT(int, RoundNumber, 120)
		ADD_BOOL(bIsRoundStarted, 116, 0x2)
		ADD_BOOL(bIsMatchStarted, 116, 0x1)
		ADD_STRUCT(GameStateObject__GameSessionType, SessionType, 112)
		ADD_STRUCT(Object__Array_Mirror, PlayerStates, 100)
		ADD_STRUCT(Object__Array_Mirror, TeamStates, 88)
		void PreProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31955);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31956);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
