#pragma once
#include "UTGame__UTPlayerInput.h"
#include "Engine__Pawn.h"
#include "UTGame__UTWeapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTConsolePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTConsolePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTConsolePlayerInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTConsolePlayerInput : public UTPlayerInput
	{
	public:
		ADD_VAR(::FloatProperty, HoverBoardPitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoPitchStopAdjustingValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoPitchCenterSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_BackToCenterSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_BackToCenterBoundary, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_LookingUpOrDownBoundary, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_PitchThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_MaxTurnSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_RampSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MagicScaleForSensitivityEdge, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MagicScaleForSensitivityMiddle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RightThumbStickDeadZoneThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftThumbStickDeadZoneThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastDeltaRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastCamLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LastAdjustZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAdjustY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistFromAimZa, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistFromAimYa, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTargetHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTargetRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAdhesionAmtZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAdhesionAmtY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFrictionMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistFromAimY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistFromAimZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDistToTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFrictionTargetTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, LastFrictionTarget)
		ADD_VAR(::FloatProperty, Dodge_Threshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_Twitchy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_TimeHeld, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_TimeToHoldBeforeFastAcceleration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_CurrMutliplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_BaseMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_DiagonalThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewAccel_YawThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlowTurnScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoVehicleCenterSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoCenterDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTurnTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLookingDown, 0x100)
		ADD_VAR(::BoolProperty, bIsLookingUp, 0x80)
		ADD_VAR(::BoolProperty, bAppliedTargetFriction, 0x40)
		ADD_VAR(::BoolProperty, bDebugTargetFriction, 0x20)
		ADD_VAR(::BoolProperty, bTargetFrictionEnabled, 0x10)
		ADD_VAR(::BoolProperty, bDebugViewAcceleration, 0x8)
		ADD_VAR(::BoolProperty, bViewAccelerationEnabled, 0x4)
		ADD_VAR(::BoolProperty, bAutoCenterVehiclePitch, 0x2)
		ADD_VAR(::BoolProperty, bAutoCenterPitch, 0x1)
		ADD_VAR(::FloatProperty, TurningAccelerationMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SensitivityMultiplier, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.PreProcessInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyViewAutoPitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAutoPitchCentering");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyViewAutoVehiclePitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAutoVehiclePitchCentering");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyViewAcceleration(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAcceleration");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyTargetAdhesion(float DeltaTime, class UTWeapon* W, int& out_YawRot, int& out_PitchRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyTargetAdhesion");
			byte* params = (byte*)malloc(16);
			*(float*)params = DeltaTime;
			*(class UTWeapon**)(params + 4) = W;
			*(int*)(params + 8) = out_YawRot;
			*(int*)(params + 12) = out_PitchRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YawRot = *(int*)(params + 8);
			out_PitchRot = *(int*)(params + 12);
			free(params);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.AdjustMouseSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyTargetFriction(float DeltaTime, class UTWeapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyTargetFriction");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			*(class UTWeapon**)(params + 4) = W;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte CheckForDoubleClickMove(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.CheckForDoubleClickMove");
			byte* params = (byte*)malloc(5);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
