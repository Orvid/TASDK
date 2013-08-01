#pragma once
namespace UnrealScript
{
	enum ProcBuilding__EBuildingStatsBrowserColumns : byte
	{
		BSBC_Name = 0,
		BSBC_Ruleset = 1,
		BSBC_NumStaticMeshComps = 2,
		BSBC_NumInstancedStaticMeshComps = 3,
		BSBC_NumInstancedTris = 4,
		BSBC_LightmapMemBytes = 5,
		BSBC_ShadowmapMemBytes = 6,
		BSBC_LODDiffuseMemBytes = 7,
		BSBC_LODLightingMemBytes = 8,
		BSBC_MAX = 9,
	};
}
