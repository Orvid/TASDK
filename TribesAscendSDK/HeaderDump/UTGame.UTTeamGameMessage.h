#pragma once
#include "Core.Object.Color.h"
#include "UTGame.UTLocalMessage.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.HUD.h"
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
	class UTTeamGameMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, AnnouncerSounds, 156)
		ADD_STRUCT(Object__Color, BlueDrawColor, 152)
		ADD_STRUCT(Object__Color, RedDrawColor, 148)
		ADD_STRUCT(ScriptString*, YouAreOnBlueMessage, 136)
		ADD_STRUCT(ScriptString*, YouAreOnRedMessage, 124)
		ADD_STRUCT(ScriptString*, RequestTeamSwapPostfix, 112)
		ADD_STRUCT(ScriptString*, RequestTeamSwapPrefix, 100)
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49419);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49425);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49432);
			byte params[16] = { NULL };
			*(int*)params = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		int GetFontSize(int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49437);
			byte params[20] = { NULL };
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI2;
			*(class PlayerReplicationInfo**)&params[12] = LocalPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49443);
			byte params[12] = { NULL };
			*(int*)params = Switch;
			*(class HUD**)&params[4] = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		Object__Color GetColor(int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49447);
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
#undef ADD_OBJECT
