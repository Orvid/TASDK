#pragma once
#include "UTGame__UTTeamAI.h"
#include "UTGame__UTCTFFlag.h"
#include "UTGame__UTSquadAI.h"
#include "Engine__Controller.h"
#include "UTGame__UTGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFTeamAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFTeamAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFTeamAI : public UTTeamAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, FriendlyFlag)
		ADD_OBJECT(UTCTFFlag, EnemyFlag)
		ADD_VAR(::FloatProperty, LastGotFlag, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AddSquadWithLeader'
		// Here lies the not-yet-implemented method 'GetPriorityFreelanceObjectiveFor'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
