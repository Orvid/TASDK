#pragma once
#include "UDKBase__UDKVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicle : public UDKVehicle
	{
	public:
		ADD_VAR(::BoolProperty, bCanCarryFlag, 0x2)
		ADD_VAR(::BoolProperty, bRequestedEntryWithFlag, 0x200000)
		ADD_VAR(::BoolProperty, bHasCustomEntryRadius, 0x10)
		ADD_OBJECT(UTVehicle, NextVehicle)
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDropDetailWhenDriving, 0x10000)
		ADD_VAR(::BoolProperty, bSpectatedView, 0x200)
		ADD_VAR(::FloatProperty, LastEnemyWarningTime, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, ReferenceMovementMesh)
		ADD_OBJECT(ParticleSystem, DisabledTemplate)
		ADD_VAR(::FloatProperty, TimeLastDisabled, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DisabledTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OldCameraPosition, 0xFFFFFFFF
		ADD_OBJECT(UTGib, DeathCameraGib)
		ADD_VAR(::FloatProperty, MinCameraDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookForwardDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CameraLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraSmoothingFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldCamPosZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SeatCameraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCollisionDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionDamageMult, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, BurnOutMaterial)
		ADD_VAR(::FloatProperty, SpawnInTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SpawnMaterialParameterCurve'!
		ADD_VAR(::NameProperty, SpawnMaterialParameterName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'HudCoords'!
		ADD_OBJECT(Texture2D, HudIcons)
		ADD_STRUCT(::VectorProperty, PassengerTeamBeaconOffset, 0xFFFFFFFF
		ADD_OBJECT(PlayerReplicationInfo, PassengerPRI)
		ADD_STRUCT(::VectorProperty, TeamBeaconOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, HealthPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastHealth, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'DropOrbIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'DropFlagIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'EnterToolTipIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'FlipToolTipIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlagBone, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, FlagRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FlagOffset, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, BoostPadSound)
		ADD_OBJECT(SoundCue, SpawnOutSound)
		ADD_OBJECT(SoundCue, SpawnInSound)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BurnTimeParameterName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_VAR(::FloatProperty, TurretExplosiveForce, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, DestroyedTurretTemplate)
		ADD_OBJECT(UTVehicleDeathPiece, DestroyedTurret)
		ADD_STRUCT(::VectorProperty, TurretOffset, 0xFFFFFFFF
		ADD_VAR(::NameProperty, TurretSocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TurretScaleControlName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterExplosionShakeRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerExplosionShakeRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, DeathExplosionShake)
		ADD_VAR(::FloatProperty, ExplosionInAirAngVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionMomentum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DelayedBurnoutCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadVehicleLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BurnOutTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BigExplosionSocket, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, SecondaryExplosion)
		ADD_OBJECT(ParticleSystem, ExplosionTemplate)
		ADD_VAR(::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageSmokeThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClientHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeTilSecondaryVehicleExplosion, 0xFFFFFFFF)
		ADD_OBJECT(Emitter, DeathExplosion)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HUDExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo' for the property named 'NeedToPickUpAnnouncement'!
		ADD_VAR(::StrProperty, VehicleNameString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VehiclePositionString, 0xFFFFFFFF)
		ADD_OBJECT(UTBot, Reservation)
		ADD_OBJECT(UTVehicleFactory, ParentFactory)
		ADD_OBJECT(SoundCue, StolenSound)
		ADD_VAR(::IntProperty, StolenAnnouncementIndex, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RanOverSound)
		ADD_OBJECT(SoundCue, LockedOnSound)
		ADD_VAR(::FloatProperty, ConsoleSteerScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDeadZone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftStickDirDeadZone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HornIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHornTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HornAIRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, LinkedEndSound)
		ADD_OBJECT(SoundCue, LinkedToCue)
		ADD_VAR(::FloatProperty, LinkHealMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialSpawnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayerStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleLostTime, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, DrivingPhysicalMaterial)
		ADD_VAR(::FloatProperty, DeflectionReverseThresh, 0xFFFFFFFF)
		ADD_OBJECT(Actor, NoPassengerObjective)
		ADD_VAR(::ByteProperty, LinkedToCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AIPurpose, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDriverHoldsFlag, 0x1)
		ADD_OBJECT(SoundCue, VehicleLockedSound)
		ADD_VAR(::BoolProperty, bIsNecrisVehicle, 0x100)
		ADD_VAR(::BoolProperty, bHasEnemyVehicleSound, 0x80)
		ADD_VAR(::BoolProperty, bStealthVehicle, 0x40)
		ADD_VAR(::BoolProperty, bShowDamageDebug, 0x20)
		ADD_VAR(::BoolProperty, bAcceptTurretJump, 0x10)
		ADD_VAR(::BoolProperty, bIsConsoleTurning, 0x8)
		ADD_VAR(::BoolProperty, bStopDeathCamera, 0x4)
		ADD_VAR(::BoolProperty, bCameraNeverHidesVehicle, 0x2)
		ADD_VAR(::BoolProperty, bFixedCamZ, 0x1)
		ADD_VAR(::BoolProperty, bNoFollowJumpZ, 0x80000000)
		ADD_VAR(::BoolProperty, bLimitCameraZLookingUp, 0x40000000)
		ADD_VAR(::BoolProperty, bNoZSmoothing, 0x20000000)
		ADD_VAR(::BoolProperty, bRotateCameraUnderVehicle, 0x10000000)
		ADD_VAR(::BoolProperty, bReducedFallingCollisionDamage, 0x8000000)
		ADD_VAR(::BoolProperty, bPlayingSpawnEffect, 0x4000000)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x2000000)
		ADD_VAR(::BoolProperty, bHasTurretExplosion, 0x1000000)
		ADD_VAR(::BoolProperty, bRagdollDriverOnDarkwalkerHorn, 0x800000)
		ADD_VAR(::BoolProperty, bInitializedVehicleEffects, 0x400000)
		ADD_VAR(::BoolProperty, bFindGroundExit, 0x100000)
		ADD_VAR(::BoolProperty, bUsingLookSteer, 0x80000)
		ADD_VAR(::BoolProperty, bLookSteerOnSimpleControls, 0x40000)
		ADD_VAR(::BoolProperty, bLookSteerOnNormalControls, 0x20000)
		ADD_VAR(::BoolProperty, bHasBeenDriven, 0x8000)
		ADD_VAR(::BoolProperty, bDriverCastsShadow, 0x4000)
		ADD_VAR(::BoolProperty, bDrawHealthOnHUD, 0x2000)
		ADD_VAR(::BoolProperty, bShouldLeaveForCombat, 0x1000)
		ADD_VAR(::BoolProperty, bNeverReset, 0x800)
		ADD_VAR(::BoolProperty, bHasWeaponBar, 0x400)
		ADD_VAR(::BoolProperty, bShouldAutoCenterViewPitch, 0x200)
		ADD_VAR(::BoolProperty, bStickDeflectionThrottle, 0x100)
		ADD_VAR(::BoolProperty, bOverrideAVRiLLocks, 0x80)
		ADD_VAR(::BoolProperty, bMustBeUpright, 0x40)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x20)
		ADD_VAR(::BoolProperty, bEnteringUnlocks, 0x8)
		ADD_VAR(::BoolProperty, bValidLinkTarget, 0x4)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
