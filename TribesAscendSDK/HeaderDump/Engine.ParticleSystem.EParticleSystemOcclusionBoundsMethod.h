#pragma once
namespace UnrealScript
{
	enum ParticleSystem__EParticleSystemOcclusionBoundsMethod : byte
	{
		EPSOBM_None = 0,
		EPSOBM_ParticleBounds = 1,
		EPSOBM_CustomBounds = 2,
		EPSOBM_MAX = 3,
	};
}
