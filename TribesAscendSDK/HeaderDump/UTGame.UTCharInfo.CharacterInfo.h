#pragma once
#include "UTGame.UTCharInfo.CustomAIData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTCharInfo__CharacterInfo
	{
	public:
		ADD_STRUCT(UTCharInfo__CustomAIData, AIData, 72)
		ADD_STRUCT(ScriptString*, Faction, 60)
		ADD_STRUCT(ScriptString*, PreviewImageMarkup, 48)
		ADD_STRUCT(ScriptString*, Description, 36)
		ADD_STRUCT(ScriptString*, CharName, 24)
		ADD_STRUCT(ScriptString*, FamilyID, 12)
		ADD_STRUCT(ScriptString*, CharID, 0)
	};
}
#undef ADD_STRUCT
