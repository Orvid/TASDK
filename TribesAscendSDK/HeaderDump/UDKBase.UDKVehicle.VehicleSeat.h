#pragma once
#include "UDKBase.UDKVehicle.WeaponEffectInfo.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "UDKBase.UDKSkelControl_TurretConstrained.h"
#include "Core.Object.Vector.h"
#include "UDKBase.UDKVehicle.VehicleSeatAnimInfo.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKVehicleMovementEffect.h"
#include "Core.Object.Pointer.h"
#include "UDKBase.UDKWeapon.h"
#include "Engine.Vehicle.h"
#include "Engine.Pawn.h"
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
	struct UDKVehicle__VehicleSeat
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, GunSocket, 16)
		ADD_STRUCT(ScriptArray<ScriptName>, GunPivotPoints, 28)
		ADD_STRUCT(ScriptArray<UDKVehicle__WeaponEffectInfo>, WeaponEffects, 56)
		ADD_STRUCT(ScriptArray<ScriptName>, TurretControls, 128)
		ADD_STRUCT(ScriptArray<class UDKSkelControl_TurretConstrained*>, TurretControllers, 140)
		ADD_STRUCT(ScriptArray<UDKVehicle__VehicleSeatAnimInfo>, m_SeatAnimInfo, 324)
		ADD_STRUCT(ScriptArray<class GameSkelCtrl_Recoil*>, m_TurretRecoilControls, 368)
		ADD_STRUCT(ScriptArray<ScriptName>, m_TurretRecoilControlNames, 380)
		ADD_BOOL(ValidFlagSeat, 428, 0x1)
		ADD_STRUCT(Rotator, FlagRotation, 416)
		ADD_STRUCT(Vector, FlagOffset, 404)
		ADD_STRUCT(ScriptName, FlagSocketName, 396)
		ADD_STRUCT(float, m_fTurnInterpSpeed, 392)
		ADD_STRUCT(Vector, m_vIdealExitLocation, 356)
		ADD_STRUCT(Vector, m_vRidingPassengerMeshOffset, 344)
		ADD_STRUCT(float, m_fViewYawLimit, 340)
		ADD_BOOL(m_bAttachPawnDirectly, 336, 0x1)
		ADD_STRUCT(Object__Vector2D, SeatIconPOS, 316)
		ADD_OBJECT(UDKVehicleMovementEffect, SeatMovementEffect, 312)
		ADD_STRUCT(float, DriverDamageMult, 304)
		ADD_OBJECT(ScriptClass, ImpactFlashLightClass, 300)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass, 292)
		ADD_STRUCT(ScriptName, SeatSocket, 284)
		ADD_STRUCT(Rotator, SeatRotation, 272)
		ADD_STRUCT(Vector, SeatOffset, 260)
		ADD_STRUCT(ScriptName, SeatBone, 252)
		ADD_BOOL(bSeatVisible, 248, 0x1)
		ADD_STRUCT(float, ViewPitchMax, 244)
		ADD_STRUCT(float, ViewPitchMin, 240)
		ADD_STRUCT(float, CameraZoomOffset, 236)
		ADD_STRUCT(Vector, CameraZoomBaseOffset, 224)
		ADD_STRUCT(ScriptName, CameraZoomTag, 216)
		ADD_STRUCT(float, CameraEyeHeight, 212)
		ADD_STRUCT(float, CameraOffset, 208)
		ADD_STRUCT(Vector, CameraSafeOffset, 196)
		ADD_STRUCT(Vector, CameraBaseOffset, 184)
		ADD_STRUCT(ScriptName, CameraTag, 176)
		ADD_BOOL(bDisableOffsetZAdjust, 172, 0x1)
		ADD_STRUCT(float, PivotFireOffsetZ, 168)
		ADD_OBJECT(Actor, AimTarget, 164)
		ADD_STRUCT(Vector, AimPoint, 152)
		ADD_STRUCT(Rotator, LastWeaponRotation, 116)
		ADD_STRUCT(Object__Pointer, FiringModeProperty, 112)
		ADD_STRUCT(Object__Pointer, FlashCountProperty, 108)
		ADD_STRUCT(Object__Pointer, FlashLocationProperty, 104)
		ADD_STRUCT(Object__Pointer, WeaponRotationProperty, 100)
		ADD_STRUCT(ScriptName, FiringModeName, 92)
		ADD_STRUCT(ScriptName, FlashCountName, 84)
		ADD_STRUCT(ScriptName, FlashLocationName, 76)
		ADD_STRUCT(ScriptName, WeaponRotationName, 68)
		ADD_STRUCT(ScriptString*, TurretVarPrefix, 44)
		ADD_STRUCT(int, BarrelIndex, 40)
		ADD_OBJECT(UDKWeapon, Gun, 12)
		ADD_OBJECT(ScriptClass, GunClass, 8)
		ADD_OBJECT(Vehicle, SeatPawn, 4)
		ADD_OBJECT(Pawn, StoragePawn, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
