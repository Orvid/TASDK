#pragma once
namespace UnrealScript
{
	enum PhysXParticleSystem__ESimulationMethod : byte
	{
		ESM_SPH = 0,
		ESM_NO_PARTICLE_INTERACTION = 1,
		ESM_MIXED_MODE = 2,
		ESM_MAX = 3,
	};
}
