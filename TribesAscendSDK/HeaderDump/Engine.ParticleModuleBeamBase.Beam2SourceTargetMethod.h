#pragma once
namespace UnrealScript
{
	enum ParticleModuleBeamBase__Beam2SourceTargetMethod : byte
	{
		PEB2STM_Default = 0,
		PEB2STM_UserSet = 1,
		PEB2STM_Emitter = 2,
		PEB2STM_Particle = 3,
		PEB2STM_Actor = 4,
		PEB2STM_MAX = 5,
	};
}
