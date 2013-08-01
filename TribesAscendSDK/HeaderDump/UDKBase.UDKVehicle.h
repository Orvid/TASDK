#pragma once
#include "Core.Object.Vector.h"
#include "UDKBase.UDKVehicle.VehicleEffect.h"
#include "UDKBase.UDKPawn.MaterialParticleEffect.h"
#include "UDKBase.UDKVehicleBase.h"
#include "UDKBase.UDKVehicle.BurnOutDatum.h"
#include "UDKBase.UDKPawn.MaterialSoundEffect.h"
#include "UDKBase.UDKVehicle.VehicleAnim.h"
#include "UDKBase.UDKVehicle.VehicleSeat.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKVehicle.VehicleSound.h"
#include "UDKBase.UDKSkelControl_Damage.h"
#include "UDKBase.UDKVehicle.DamageParamScales.h"
#include "UDKBase.UDKVehicle.FDamageMorphTargets.h"
#include "UDKBase.UDKBot.h"
#include "Engine.Controller.h"
#include "UDKBase.UDKPawn.UTTakeHitInfo.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.SoundCue.h"
#include "Core.Object.Rotator.h"
#include "UDKBase.UDKPlayerController.h"
#include "UDKBase.UDKForcedDirectionVolume.h"
#include "Engine.Pawn.h"
#include "UDKBase.UDKProjectile.h"
#include "Engine.TeamInfo.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKVehicle : public UDKVehicleBase
	{
	public:
		ADD_BOOL(bAllowedExit, 1548, 0x8000)
		ADD_BOOL(bEjectKilledBodies, 1548, 0x1)
		ADD_STRUCT(ScriptArray<UDKVehicle__BurnOutDatum>, BurnOutMaterialInstances, 1556)
		ADD_STRUCT(ScriptArray<UDKPawn__MaterialSoundEffect>, TireSoundList, 1572)
		ADD_STRUCT(ScriptArray<UDKPawn__MaterialParticleEffect>, WheelParticleEffects, 1596)
		ADD_STRUCT(ScriptArray<int>, GroundEffectIndices, 1648)
		ADD_STRUCT(ScriptArray<UDKVehicle__VehicleSeat>, Seats, 1688)
		ADD_STRUCT(ScriptArray<UDKVehicle__VehicleAnim>, VehicleAnims, 1704)
		ADD_STRUCT(ScriptArray<UDKVehicle__VehicleSound>, VehicleSounds, 1716)
		ADD_STRUCT(ScriptArray<UDKVehicle__DamageParamScales>, DamageParamScaleLevels, 1768)
		ADD_STRUCT(ScriptArray<class UDKSkelControl_Damage*>, DamageSkelControls, 1780)
		ADD_STRUCT(ScriptArray<UDKVehicle__FDamageMorphTargets>, DamageMorphTargets, 1792)
		ADD_STRUCT(ScriptArray<UDKVehicle__VehicleEffect>, VehicleEffects, 1860)
		ADD_STRUCT(ScriptArray<int>, ContrailEffectIndices, 1888)
		ADD_STRUCT(ScriptArray<class UDKBot*>, Trackers, 1912)
		ADD_STRUCT(Vector, HUDLocation, 1960)
		ADD_STRUCT(float, ShowLockedMaxDist, 1956)
		ADD_STRUCT(float, LastPostRenderTraceTime, 1952)
		ADD_STRUCT(float, TeamBeaconMaxDist, 1948)
		ADD_STRUCT(float, MinRunOverWarningAim, 1944)
		ADD_STRUCT(float, LastRunOverWarningTime, 1940)
		ADD_STRUCT(float, MinRunOverSpeed, 1936)
		ADD_STRUCT(float, ResetTime, 1932)
		ADD_STRUCT(float, ExtraReachDownThreshold, 1928)
		ADD_STRUCT(byte, Team, 1924)
		ADD_STRUCT(float, ObjectiveGetOutDist, 1908)
		ADD_STRUCT(ScriptName, ContrailColorParameterName, 1900)
		ADD_STRUCT(ScriptName, WaterEffectType, 1880)
		ADD_STRUCT(float, LastJumpOutCheck, 1876)
		ADD_OBJECT(Controller, KillerController, 1872)
		ADD_STRUCT(float, LastTakeHitTimeout, 1856)
		ADD_STRUCT(UDKPawn__UTTakeHitInfo, LastTakeHitInfo, 1812)
		ADD_OBJECT(MaterialInstanceConstant, DamageMaterialInstance, 1804)
		ADD_STRUCT(float, CustomGravityScaling, 1764)
		ADD_OBJECT(SoundCue, SmallChunkImpactSound, 1760)
		ADD_OBJECT(SoundCue, MediumChunkImpactSound, 1756)
		ADD_OBJECT(SoundCue, LargeChunkImpactSound, 1752)
		ADD_STRUCT(float, LastDeathImpactTime, 1748)
		ADD_STRUCT(float, TimeInDestroyablePenetration, 1744)
		ADD_STRUCT(float, DestroyOnPenetrationDuration, 1740)
		ADD_STRUCT(float, DestroyOnPenetrationThreshold, 1736)
		ADD_STRUCT(ScriptName, DrivingAnim, 1728)
		ADD_STRUCT(int, SeatMask, 1700)
		ADD_STRUCT(Rotator, WeaponRotation, 1676)
		ADD_OBJECT(ParticleSystem, WaterGroundEffect, 1672)
		ADD_STRUCT(ScriptName, GroundEffectDistParameterName, 1664)
		ADD_STRUCT(float, MaxGroundEffectDist, 1660)
		ADD_STRUCT(float, AccumulatedWaterDamage, 1644)
		ADD_STRUCT(float, WaterDamage, 1640)
		ADD_STRUCT(float, OccupiedUpsideDownDamagePerSec, 1636)
		ADD_STRUCT(float, UpsideDownDamagePerSec, 1632)
		ADD_STRUCT(float, AccruedFireDamage, 1628)
		ADD_STRUCT(float, FireDamagePerSec, 1624)
		ADD_STRUCT(float, FireDamageThreshold, 1620)
		ADD_STRUCT(float, FlippedCount, 1612)
		ADD_STRUCT(float, LastCheckUpsideDownTime, 1608)
		ADD_STRUCT(float, MaxWheelEffectDistSq, 1592)
		ADD_STRUCT(ScriptName, CurrentTireMaterial, 1584)
		ADD_STRUCT(float, RemainingBurn, 1552)
		ADD_BOOL(bForceSpinWarmup, 1548, 0x800000)
		ADD_BOOL(bGrab2, 1548, 0x400000)
		ADD_BOOL(bGrab1, 1548, 0x200000)
		ADD_BOOL(bTrickJumping, 1548, 0x100000)
		ADD_BOOL(bDisableRepulsorsAtMaxFallSpeed, 1548, 0x80000)
		ADD_BOOL(bTeamLocked, 1548, 0x40000)
		ADD_BOOL(bShowLocked, 1548, 0x20000)
		ADD_BOOL(bUseAlternatePaths, 1548, 0x10000)
		ADD_BOOL(bFloatWhenDriven, 1548, 0x4000)
		ADD_BOOL(bJostleWhileDriving, 1548, 0x2000)
		ADD_BOOL(bDeadVehicle, 1548, 0x1000)
		ADD_BOOL(bIsInDestroyablePenetration, 1548, 0x800)
		ADD_BOOL(bTakeWaterDamageWhileDriving, 1548, 0x400)
		ADD_BOOL(bIsScraping, 1548, 0x200)
		ADD_BOOL(bEjectPassengersWhenFlipped, 1548, 0x100)
		ADD_BOOL(bIsBurning, 1548, 0x80)
		ADD_BOOL(bIsDisabled, 1548, 0x40)
		ADD_BOOL(bNoZDamping, 1548, 0x20)
		ADD_BOOL(bNoZDampingInAir, 1548, 0x10)
		ADD_BOOL(bFrontalCollisionWithFixed, 1548, 0x8)
		ADD_BOOL(bFrontalCollision, 1548, 0x4)
		ADD_BOOL(bHomingTarget, 1548, 0x2)
		bool OnTouchForcedDirVolume(class UDKForcedDirectionVolume* Vol)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34850);
			byte params[8] = { NULL };
			*(class UDKForcedDirectionVolume**)params = Vol;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptClass* GetRanOverDamageType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35818);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		Rotator SeatWeaponRotation(int SeatIndex, Rotator NewRot, bool bReadValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36035);
			byte params[32] = { NULL };
			*(int*)params = SeatIndex;
			*(Rotator*)&params[4] = NewRot;
			*(bool*)&params[16] = bReadValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[20];
		}
		Vector SeatFlashLocation(int SeatIndex, Vector NewLoc, bool bReadValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36040);
			byte params[32] = { NULL };
			*(int*)params = SeatIndex;
			*(Vector*)&params[4] = NewLoc;
			*(bool*)&params[16] = bReadValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[20];
		}
		byte SeatFlashCount(int SeatIndex, byte NewCount, bool bReadValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36045);
			byte params[10] = { NULL };
			*(int*)params = SeatIndex;
			params[4] = NewCount;
			*(bool*)&params[8] = bReadValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[12];
		}
		byte SeatFiringMode(int SeatIndex, byte NewFireMode, bool bReadValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36050);
			byte params[10] = { NULL };
			*(int*)params = SeatIndex;
			params[4] = NewFireMode;
			*(bool*)&params[8] = bReadValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[12];
		}
		void ForceWeaponRotation(int SeatIndex, Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36055);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			*(Rotator*)&params[4] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetSeatPivotPoint(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36058);
			byte params[16] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		int GetBarrelIndex(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36061);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool IsSeatControllerReplicationViewer(int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36064);
			byte params[8] = { NULL };
			*(int*)params = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLocalOnVehicle(class Pawn* InP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36067);
			byte params[8] = { NULL };
			*(class Pawn**)params = InP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36073);
			byte params[4] = { NULL };
			*(class UDKProjectile**)params = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPropertyChange(ScriptName PropName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36075);
			byte params[8] = { NULL };
			*(ScriptName*)params = PropName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36077);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PlayTakeHitEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36080);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedHealthChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JumpOutCheck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36082);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxRiseForce()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36083);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool CheckAutoDestruct(class TeamInfo* InstigatorTeam, float CheckRadius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36085);
			byte params[12] = { NULL };
			*(class TeamInfo**)params = InstigatorTeam;
			*(float*)&params[4] = CheckRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SelfDestruct(class Actor* ImpactedActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36089);
			byte params[4] = { NULL };
			*(class Actor**)params = ImpactedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36091);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36093);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool InUseableRange(class UDKPlayerController* PC, float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36098);
			byte params[12] = { NULL };
			*(class UDKPlayerController**)params = PC;
			*(float*)&params[4] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36102);
			byte params[12] = { NULL };
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitDamageSkel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36104);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDamageMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36105);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyMorphDamage(Vector HitLocation, int Damage, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36106);
			byte params[28] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = Damage;
			*(Vector*)&params[16] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MorphTargetDestroyed(int MorphNodeIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36110);
			byte params[4] = { NULL };
			*(int*)params = MorphNodeIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RBPenetrationDestroy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36112);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeWaterDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36113);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36114);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeFireDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36115);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitRigidBody(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PrimComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36116);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PrimComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHoverboardDustEffect(float DustHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36118);
			byte params[4] = { NULL };
			*(float*)params = DustHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
