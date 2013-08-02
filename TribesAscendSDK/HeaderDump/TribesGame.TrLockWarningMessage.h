#pragma once
namespace UnrealScript
{
	class TrLockWarningMessage;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTLocalMessage.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrLockWarningMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(Object__Color, YellowColor, 128)
		ADD_STRUCT(Object__Color, RedColor, 124)
		ADD_STRUCT(ScriptString*, RadarLockString, 112)
		ADD_STRUCT(ScriptString*, MissileLockOnString, 100)
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98641);
			byte params[2] = { NULL };
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[1];
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98644);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		Object__Color GetColor(int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98651);
			byte params[20] = { NULL };
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[16];
		}
	};
}
#undef ADD_STRUCT
