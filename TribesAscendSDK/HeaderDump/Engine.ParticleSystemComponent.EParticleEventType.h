#pragma once
namespace UnrealScript
{
	enum ParticleSystemComponent__EParticleEventType : byte
	{
		EPET_Any = 0,
		EPET_Spawn = 1,
		EPET_Death = 2,
		EPET_Collision = 3,
		EPET_Kismet = 4,
		EPET_MAX = 5,
	};
}
