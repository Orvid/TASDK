#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployableMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployableMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, DeployableAmmoDepleted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableAmmoRemaining, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramInvalidDeploySpot, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramOnlyOutside, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramTooCloseToAnotherDeployable, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramTooCloseToEnemyBase, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableMessage.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
