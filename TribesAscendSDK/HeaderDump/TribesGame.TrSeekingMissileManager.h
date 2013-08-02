#pragma once
namespace UnrealScript
{
	class TrSeekingMissileManager;
}
#include "Engine.Info.h"
#include "Engine.Pawn.h"
#include "TribesGame.TrDevice_SaberLauncher.h"
#include "TribesGame.TrObject.EMissileLock.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrProj_TrackingMissile.h"
#include "TribesGame.TrSeekingMissileManager.ETrackingMissileEvent.h"
#include "TribesGame.TrSeekingMissileManager.SeekingMissileInfo.h"
#include "TribesGame.TrSeekingMissileManager.TargetingSaberLauncherInfo.h"
#include "TribesGame.TrVehicle.h"
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
	class TrSeekingMissileManager : public Info
	{
	public:
		typedef TrSeekingMissileManager__ETrackingMissileEvent ETrackingMissileEvent;
		typedef TrSeekingMissileManager__TargetingSaberLauncherInfo TargetingSaberLauncherInfo;
		typedef TrSeekingMissileManager__SeekingMissileInfo SeekingMissileInfo;
		ADD_STRUCT(ScriptArray<TrSeekingMissileManager__TargetingSaberLauncherInfo>, ActiveTargetingSaberLaunchers, 488)
		ADD_STRUCT(ScriptArray<TrSeekingMissileManager__SeekingMissileInfo>, ActiveSeekingMissiles, 476)
		ADD_STRUCT(int, RepCounter, 500)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110782);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToAdd, TrObject__EMissileLock MissileLockValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110792);
			byte params[5] = { NULL };
			*(class TrDevice_SaberLauncher**)params = SaberLauncherToAdd;
			*(TrObject__EMissileLock*)&params[4] = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110802);
			byte params[4] = { NULL };
			*(class TrDevice_SaberLauncher**)params = SaberLauncherToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumSaberLaunchersTargetingController(class TrPlayerController* Controller, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110809);
			byte params[12] = { NULL };
			*(class TrPlayerController**)params = Controller;
			*(bool*)&params[4] = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetNumSaberLaunchersTargetingVehicle(class TrVehicle* targetVehicle, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110815);
			byte params[12] = { NULL };
			*(class TrVehicle**)params = targetVehicle;
			*(bool*)&params[4] = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddMissile(class TrProj_TrackingMissile* MissileToAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110821);
			byte params[4] = { NULL };
			*(class TrProj_TrackingMissile**)params = MissileToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveMissile(class TrProj_TrackingMissile* MissileToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110831);
			byte params[4] = { NULL };
			*(class TrProj_TrackingMissile**)params = MissileToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumMissilesTrackingController(class TrPlayerController* Controller)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110837);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = Controller;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetNumMissilesTrackingVehicle(class TrVehicle* targetVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110842);
			byte params[8] = { NULL };
			*(class TrVehicle**)params = targetVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void VictimControllerUpdated(class TrPlayerController* VictimController, TrSeekingMissileManager__ETrackingMissileEvent MissileEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110847);
			byte params[5] = { NULL };
			*(class TrPlayerController**)params = VictimController;
			*(TrSeekingMissileManager__ETrackingMissileEvent*)&params[4] = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TargetVehicleUpdated(class TrVehicle* targetVehicle, TrSeekingMissileManager__ETrackingMissileEvent MissileEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110852);
			byte params[5] = { NULL };
			*(class TrVehicle**)params = targetVehicle;
			*(TrSeekingMissileManager__ETrackingMissileEvent*)&params[4] = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110859);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110861);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110863);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110865);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftVehicle(class Pawn* LeavingPawn, class TrVehicle* Vehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110867);
			byte params[8] = { NULL };
			*(class Pawn**)params = LeavingPawn;
			*(class TrVehicle**)&params[4] = Vehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredVehicle(class Pawn* EnteringPawn, class TrVehicle* Vehicle, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110875);
			byte params[12] = { NULL };
			*(class Pawn**)params = EnteringPawn;
			*(class TrVehicle**)&params[4] = Vehicle;
			*(int*)&params[8] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
