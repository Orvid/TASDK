#pragma once
namespace UnrealScript
{
	enum MaterialInterface__EMaterialUsage : byte
	{
		MATUSAGE_SkeletalMesh = 0,
		MATUSAGE_FracturedMeshes = 1,
		MATUSAGE_ParticleSprites = 2,
		MATUSAGE_BeamTrails = 3,
		MATUSAGE_ParticleSubUV = 4,
		MATUSAGE_SpeedTree = 5,
		MATUSAGE_StaticLighting = 6,
		MATUSAGE_GammaCorrection = 7,
		MATUSAGE_LensFlare = 8,
		MATUSAGE_InstancedMeshParticles = 9,
		MATUSAGE_FluidSurface = 10,
		MATUSAGE_Decals = 11,
		MATUSAGE_MaterialEffect = 12,
		MATUSAGE_MorphTargets = 13,
		MATUSAGE_FogVolumes = 14,
		MATUSAGE_RadialBlur = 15,
		MATUSAGE_InstancedMeshes = 16,
		MATUSAGE_SplineMesh = 17,
		MATUSAGE_ScreenDoorFade = 18,
		MATUSAGE_APEXMesh = 19,
		MATUSAGE_Terrain = 20,
		MATUSAGE_Landscape = 21,
		MATUSAGE_MAX = 22,
	};
}
