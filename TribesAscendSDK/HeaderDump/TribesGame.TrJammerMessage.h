#pragma once
namespace UnrealScript
{
	class TrJammerMessage;
}
#include "Core.Object.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTLocalMessage.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrJammerMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, JammedByEnemyJammerPack, 148)
		ADD_STRUCT(ScriptString*, JammingViaOtherDropJammer, 136)
		ADD_STRUCT(ScriptString*, JammedByEnemyDropJammer, 124)
		ADD_STRUCT(ScriptString*, JammingForOther, 112)
		ADD_STRUCT(ScriptString*, JammingViaOther, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98355);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
	};
}
#undef ADD_STRUCT
