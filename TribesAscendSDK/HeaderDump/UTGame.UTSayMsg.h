#pragma once
#include "Core.Object.Color.h"
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSayMsg : public UTLocalMessage
	{
	public:
		ADD_STRUCT(Object__Color, BlueTeamColor, 104)
		ADD_STRUCT(Object__Color, RedTeamColor, 100)
		Object__Color GetConsoleColor(class PlayerReplicationInfo* RelatedPRI_1)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49007);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = RelatedPRI_1;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[4];
		}
	};
}
#undef ADD_STRUCT
