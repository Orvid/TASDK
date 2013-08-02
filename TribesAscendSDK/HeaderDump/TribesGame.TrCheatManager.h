#pragma once
namespace UnrealScript
{
	class TrCheatManager;
}
#include "Engine.Weapon.h"
#include "UTGame.UTCheatManager.h"
namespace UnrealScript
{
	class TrCheatManager : public UTCheatManager
	{
	public:
		class Weapon* GiveWeapon(ScriptString* WeaponClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74480);
			byte params[16] = { NULL };
			*(ScriptString**)params = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[12];
		}
	};
}
