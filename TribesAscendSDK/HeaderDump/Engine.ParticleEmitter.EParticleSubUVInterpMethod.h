#pragma once
namespace UnrealScript
{
	enum ParticleEmitter__EParticleSubUVInterpMethod : byte
	{
		PSUVIM_None = 0,
		PSUVIM_Linear = 1,
		PSUVIM_Linear_Blend = 2,
		PSUVIM_Random = 3,
		PSUVIM_Random_Blend = 4,
		PSUVIM_MAX = 5,
	};
}
