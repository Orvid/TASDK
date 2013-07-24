#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.WorldInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.WorldInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.WorldInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WorldInfo : public ZoneInfo
	{
	public:
		ADD_VAR(::ByteProperty, NetMode, 0xFFFFFFFF)
		ADD_OBJECT(GameInfo, Game)
		ADD_VAR(::FloatProperty, TimeSeconds, 0xFFFFFFFF)
		ADD_OBJECT(GameReplicationInfo, GRI)
		ADD_STRUCT(::VectorProperty, DefaultColorScale, 0xFFFFFFFF
		ADD_OBJECT(EmitterPool, MyEmitterPool)
		ADD_VAR(::FloatProperty, TimeDilation, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, Pauser)
		ADD_VAR(::FloatProperty, MoveRepSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayersOnly, 0x200)
		ADD_VAR(::FloatProperty, StallZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequestedBlockOnAsyncLoading, 0x80)
		ADD_VAR(::FloatProperty, PauseDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorldGravityZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayersOnlyPending, 0x400)
		ADD_VAR(::FloatProperty, DemoPlayTimeDilation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MusicTrackDataStructures.MusicTrackStruct' for the property named 'ReplicatedMusicTrack'!
		ADD_VAR(::ByteProperty, NextTravelType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NextURL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NextSwitchCountdown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EmitterPoolClassPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DecalManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(DecalManager, MyDecalManager)
		ADD_VAR(::StrProperty, FractureManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(FractureManager, MyFractureManager)
		ADD_VAR(::StrProperty, ParticleEventManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(ParticleEventManager, MyParticleEventManager)
		ADD_VAR(::BoolProperty, bUseConsoleInput, 0x20000)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'DefaultPostProcessSettings'!
		ADD_OBJECT(PostProcessChain, WorldPostProcessChain)
		ADD_VAR(::BoolProperty, bPersistPostProcessToNextLevel, 0x1)
		ADD_VAR(::BoolProperty, bFogEnabled, 0x2)
		ADD_VAR(::BoolProperty, bBumpOffsetEnabled, 0x4)
		ADD_VAR(::BoolProperty, bMapNeedsLightingFullyRebuilt, 0x8)
		ADD_VAR(::BoolProperty, bMapHasDLEsOutsideOfImportanceVolume, 0x10)
		ADD_VAR(::BoolProperty, bMapHasMultipleDominantLightsAffectingOnePrimitive, 0x20)
		ADD_VAR(::BoolProperty, bMapHasPathingErrors, 0x40)
		ADD_VAR(::BoolProperty, bBegunPlay, 0x100)
		ADD_VAR(::BoolProperty, bDropDetail, 0x800)
		ADD_VAR(::BoolProperty, bAggressiveLOD, 0x1000)
		ADD_VAR(::BoolProperty, bStartup, 0x2000)
		ADD_VAR(::BoolProperty, bPathsRebuilt, 0x4000)
		ADD_VAR(::BoolProperty, bHasPathNodes, 0x8000)
		ADD_VAR(::BoolProperty, bIsMenuLevel, 0x10000)
		ADD_VAR(::BoolProperty, bNoDefaultInventoryForPlayer, 0x40000)
		ADD_VAR(::BoolProperty, bNoPathWarnings, 0x80000)
		ADD_VAR(::BoolProperty, bHighPriorityLoading, 0x100000)
		ADD_VAR(::BoolProperty, bHighPriorityLoadingLocal, 0x200000)
		ADD_VAR(::BoolProperty, bUseProcBuildingRulesetOverride, 0x400000)
		ADD_VAR(::BoolProperty, bSupportDoubleBufferedPhysics, 0x800000)
		ADD_VAR(::BoolProperty, bEnableChanceOfPhysicsChunkOverride, 0x1000000)
		ADD_VAR(::BoolProperty, bLimitExplosionChunkSize, 0x2000000)
		ADD_VAR(::BoolProperty, bLimitDamageChunkSize, 0x4000000)
		ADD_VAR(::BoolProperty, bPrecomputeVisibility, 0x8000000)
		ADD_VAR(::BoolProperty, bPlaceCellsOnSurfaces, 0x10000000)
		ADD_VAR(::BoolProperty, bAllowLightEnvSphericalHarmonicLights, 0x20000000)
		ADD_VAR(::BoolProperty, bAllowModulateBetterShadows, 0x40000000)
		ADD_VAR(::BoolProperty, bIncreaseFogNearPrecision, 0x80000000)
		ADD_VAR(::BoolProperty, bUseGlobalIllumination, 0x1)
		ADD_VAR(::BoolProperty, bForceNoPrecomputedLighting, 0x2)
		ADD_VAR(::BoolProperty, bSimpleLightmapsStoredInLinearSpace, 0x4)
		ADD_VAR(::BoolProperty, bHaveActiveCrowd, 0x8)
		ADD_VAR(::BoolProperty, bAllowHostMigration, 0x10)
		ADD_VAR(::FloatProperty, SquintModeKernelSize, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessVolume, HighestPriorityPostProcessVolume)
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.ReverbSettings' for the property named 'DefaultReverbSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.InteriorSettings' for the property named 'DefaultAmbientZoneSettings'!
		ADD_VAR(::FloatProperty, FogStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogEnd, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FogColor'!
		ADD_VAR(::FloatProperty, BumpEnd, 0xFFFFFFFF)
		ADD_OBJECT(ReverbVolume, HighestPriorityReverbVolume)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'LastTimeUnbuiltLightingWasEncountered'!
		ADD_OBJECT(BookMark, BookMarks)
		ADD_OBJECT(KismetBookMark, KismetBookMarks)
		ADD_VAR(::FloatProperty, RealTimeSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AudioTimeSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RealTimeToUnPause, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VisibleGroups, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SelectedGroups, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DefaultTexture)
		ADD_OBJECT(Texture2D, WireframeTexture)
		ADD_OBJECT(Texture2D, WhiteSquareTexture)
		ADD_OBJECT(Texture2D, LargeVertex)
		ADD_OBJECT(Texture2D, BSPVertex)
		ADD_VAR(::ByteProperty, VisibilityAggressiveness, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LevelLightingQuality, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ComputerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EngineVersion, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MinNetVersion, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultGravityZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GlobalGravityZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RBPhysicsGravityScaling, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, NavigationPointList)
		ADD_OBJECT(Controller, ControllerList)
		ADD_OBJECT(Pawn, PawnList)
		ADD_OBJECT(CoverLink, CoverList)
		ADD_OBJECT(Pylon, PylonList)
		ADD_VAR(::IntProperty, PackedLightAndShadowMapTextureSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CommittedPersistentLevelName, 0xFFFFFFFF)
		ADD_OBJECT(ObjectReferencer, PersistentMapForcedObjects)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MusicTrackDataStructures.MusicTrackStruct' for the property named 'CurrentMusicTrack'!
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Author, 0xFFFFFFFF)
		ADD_OBJECT(MapInfo, MyMapInfo)
		ADD_OBJECT(ProcBuildingRuleset, ProcBuildingRulesetOverride)
		ADD_VAR(::FloatProperty, MaxPhysicsDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPhysicsSubsteps, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.WorldInfo.PhysXSceneProperties' for the property named 'PhysicsProperties'!
		ADD_VAR(::FloatProperty, DefaultSkinWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ApexLODResourceBudget, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.WorldInfo.ApexModuleDestructibleSettings' for the property named 'DestructibleSettings'!
		ADD_OBJECT(PhysicsLODVerticalEmitter, EmitterVertical)
		// WARNING: Unknown structure type 'ScriptStruct Engine.WorldInfo.PhysXVerticalProperties' for the property named 'VerticalProperties'!
		ADD_VAR(::FloatProperty, ChanceOfPhysicsChunkOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxExplosionChunkSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDamageChunkSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FractureExplosionVelScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxNumFacturedChunksToSpawnInAFrame, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumFacturedChunksSpawnedThisFrame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FracturedMeshWeaponDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VisibilityCellSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLitIndirectBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLitIndirectContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterShadowedIndirectBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterShadowedIndirectContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, ImageReflectionEnvironmentTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ImageReflectionEnvironmentColor'!
		ADD_VAR(::FloatProperty, ImageReflectionEnvironmentRotation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'ScreenMessages'!
		ADD_VAR(::IntProperty, MaxTrianglesPerLeaf, 0xFFFFFFFF)
		ADD_OBJECT(LightmassLevelSettings, LMLevelSettings)
		// WARNING: Unknown structure type 'ScriptStruct Engine.WorldInfo.LightmassWorldInfoSettings' for the property named 'LightmassSettings'!
		ADD_OBJECT(CrowdPopulationManagerBase, PopulationManager)
		// WARNING: Unknown structure type 'ScriptStruct Engine.WorldInfo.HostMigrationState' for the property named 'PeerHostMigration'!
		ADD_VAR(::FloatProperty, HostMigrationTimeout, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
