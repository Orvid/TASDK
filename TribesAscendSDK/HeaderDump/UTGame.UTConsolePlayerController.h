#pragma once
namespace UnrealScript
{
	class UTConsolePlayerController;
}
#include "Engine.Pawn.h"
#include "UTGame.UTConsolePlayerController.ProfileSettingToUE3BindingDatum.h"
#include "UTGame.UTPlayerController.h"
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
	class UTConsolePlayerController : public UTPlayerController
	{
	public:
		typedef UTConsolePlayerController__ProfileSettingToUE3BindingDatum ProfileSettingToUE3BindingDatum;
		ADD_STRUCT(ScriptArray<UTConsolePlayerController__ProfileSettingToUE3BindingDatum>, ProfileSettingToUE3BindingMapping360, 2180)
		ADD_STRUCT(ScriptArray<UTConsolePlayerController__ProfileSettingToUE3BindingDatum>, ProfileSettingToUE3BindingMappingPS3, 2192)
		ADD_BOOL(bDebugTargetAdhesion, 2176, 0x2)
		ADD_BOOL(bTargetAdhesionEnabled, 2176, 0x1)
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44105);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44112);
			byte params[8] = { NULL };
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44115);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44117);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClientSmartUse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44119);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44120);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44122);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44123);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPlayerMovementInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44124);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
