#pragma once
namespace UnrealScript
{
	class TrDeathMessage;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTLocalMessage.h"
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
	class TrDeathMessage : public UTLocalMessage
	{
	public:
		ADD_BOOL(bNoConsoleDeathMessages, 124, 0x1)
		ADD_STRUCT(ScriptString*, SomeoneString, 112)
		ADD_STRUCT(ScriptString*, KilledString, 100)
		Object__Color GetConsoleColor(class PlayerReplicationInfo* RelatedPRI_1)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79802);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = RelatedPRI_1;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[4];
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79805);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79814);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
