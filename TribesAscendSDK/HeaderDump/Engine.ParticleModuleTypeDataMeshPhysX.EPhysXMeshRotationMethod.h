#pragma once
namespace UnrealScript
{
	enum ParticleModuleTypeDataMeshPhysX__EPhysXMeshRotationMethod : byte
	{
		PMRM_Disabled = 0,
		PMRM_Spherical = 1,
		PMRM_Box = 2,
		PMRM_LongBox = 3,
		PMRM_FlatBox = 4,
		PMRM_Velocity = 5,
		PMRM_MAX = 6,
	};
}
