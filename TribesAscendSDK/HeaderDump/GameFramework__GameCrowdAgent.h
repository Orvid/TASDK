#pragma once
#include "Engine__Canvas.h"
#include "GameFramework__GameCrowdGroup.h"
#include "Engine__CrowdAgentBase.h"
#include "Engine__Texture2D.h"
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__GameCrowdDestination.h"
#include "Engine__SoundCue.h"
#include "Engine__NavigationHandle.h"
#include "Engine__HUD.h"
#include "GameFramework__SeqAct_PlayAgentAnimation.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAgent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameCrowdAgent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdAgent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdAgent : public CrowdAgentBase
	{
	public:
		ADD_VAR(::FloatProperty, InitialLastRenderTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SpawnOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MaxLOSLifeDistanceSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredGroupRadiusSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredGroupRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReachThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RandomBehaviorInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SeePlayerInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSeePlayerDistSq, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgentBehavior, CurrentBehavior)
		ADD_OBJECT(SoundCue, AmbientSoundCue)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BeaconColor'!
		ADD_OBJECT(Texture2D, BeaconTexture)
		ADD_STRUCT(::VectorProperty, BeaconOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, BeaconMaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRunningSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxWalkingSpeed, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgent, MyArchetype)
		ADD_VAR(::FloatProperty, NotVisibleTickScalingFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NotVisibleLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPathingAttempt, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WalkableFloorZ, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObstacleCheckCount, 0xFFFFFFFF)
		ADD_OBJECT(NavigationHandle, NavigationHandle)
		ADD_OBJECT(ScriptClass, NavigationHandleClass)
		ADD_STRUCT(::VectorProperty, SearchExtent, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, IntermediatePoint, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, GroundOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastKnownGoodPosition, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, VisibleProximityLODDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProximityLODDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EyeZOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MeshMaxScale3D, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MeshMinScale3D, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MaxYawRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotateToTargetSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VelocityDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowPathStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MatchVelStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroupAttractionStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidOtherRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidPlayerStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidOtherStrength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AwareUpdateInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwareRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastGroundZ, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentConformTraceInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConformTraceInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConformTraceDist, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ConformType, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdGroup, MyGroup)
		ADD_VAR(::BoolProperty, bIsInSpawnPool, 0x8000)
		ADD_VAR(::BoolProperty, bHasNotifiedSpawner, 0x4000)
		ADD_VAR(::BoolProperty, bPreferVisibleDestinationOnSpawn, 0x2000)
		ADD_VAR(::BoolProperty, bPreferVisibleDestination, 0x1000)
		ADD_VAR(::BoolProperty, bWantsGroupIdle, 0x800)
		ADD_VAR(::BoolProperty, bIsPanicked, 0x400)
		ADD_VAR(::BoolProperty, bPotentialEncounter, 0x200)
		ADD_VAR(::BoolProperty, bClampMovementSpeed, 0x100)
		ADD_VAR(::BoolProperty, bSimulateThisTick, 0x80)
		ADD_VAR(::BoolProperty, bBadHitNormal, 0x40)
		ADD_VAR(::BoolProperty, bHitObstacle, 0x20)
		ADD_VAR(::BoolProperty, bAllowPitching, 0x10)
		ADD_VAR(::BoolProperty, bWantsSeePlayerNotification, 0x8)
		ADD_VAR(::BoolProperty, bUseNavMeshPathing, 0x4)
		ADD_VAR(::BoolProperty, bCheckForObstacles, 0x2)
		ADD_VAR(::BoolProperty, bUniformScale, 0x1)
		ADD_VAR(::IntProperty, AwareUpdateFrameCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConformTraceFrameCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadBodyDuration, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpZTranslation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExternalForce, 0xFFFFFFFF
		ADD_OBJECT(GameCrowdDestination, PreviousDestination)
		ADD_OBJECT(GameCrowdDestination, BehaviorDestination)
		ADD_OBJECT(GameCrowdDestination, CurrentDestination)
		ADD_VAR(::FloatProperty, AvoidanceShare, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreferredVelocity, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'PickBehaviorFrom'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'IsPanicked'
		// Here lies the not-yet-implemented method 'SetPanic'
		// Here lies the not-yet-implemented method 'WaitForGroupMembers'
		// Here lies the not-yet-implemented method 'SetCurrentDestination'
		// Here lies the not-yet-implemented method 'SetMaxSpeed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'KillAgent'
		// Here lies the not-yet-implemented method 'ResetPooledAgent'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'SetLighting'
		// Here lies the not-yet-implemented method 'InitializeAgent'
		// Here lies the not-yet-implemented method 'OnPlayAgentAnimation'
		// Here lies the not-yet-implemented method 'PlayIdleAnimation'
		// Here lies the not-yet-implemented method 'StopIdleAnimation'
		// Here lies the not-yet-implemented method 'HandlePotentialAgentEncounter'
		// Here lies the not-yet-implemented method 'PlaySpawnBehavior'
		// Here lies the not-yet-implemented method 'NotifySeePlayer'
		// Here lies the not-yet-implemented method 'TryRandomBehavior'
		// Here lies the not-yet-implemented method 'ResetSeePlayer'
		// Here lies the not-yet-implemented method 'ActivateBehavior'
		// Here lies the not-yet-implemented method 'SetCurrentBehavior'
		// Here lies the not-yet-implemented method 'ActivateInstancedBehavior'
		// Here lies the not-yet-implemented method 'StopBehavior'
		// Here lies the not-yet-implemented method 'IsIdle'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'UpdateIntermediatePoint'
		// Here lies the not-yet-implemented method 'PlayDeath'
		// Here lies the not-yet-implemented method 'FireDeathEvent'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'OverlappedActorEvent'
		// Here lies the not-yet-implemented method 'InitNavigationHandle'
		// Here lies the not-yet-implemented method 'GeneratePathToActor'
		// Here lies the not-yet-implemented method 'NativePostRenderFor'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'GetDestString'
		// Here lies the not-yet-implemented method 'GetBehaviorString'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
