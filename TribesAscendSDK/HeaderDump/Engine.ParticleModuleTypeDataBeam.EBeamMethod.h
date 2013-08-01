#pragma once
namespace UnrealScript
{
	enum ParticleModuleTypeDataBeam__EBeamMethod : byte
	{
		PEBM_Distance = 0,
		PEBM_EndPoints = 1,
		PEBM_EndPoints_Interpolated = 2,
		PEBM_UserSet_EndPoints = 3,
		PEBM_UserSet_EndPoints_Interpolated = 4,
		PEBM_MAX = 5,
	};
}
