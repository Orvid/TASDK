#pragma once
namespace UnrealScript
{
	enum SeqEvent_ParticleEvent__EParticleEventOutputType : byte
	{
		ePARTICLEOUT_Spawn = 0,
		ePARTICLEOUT_Death = 1,
		ePARTICLEOUT_Collision = 2,
		ePARTICLEOUT_Kismet = 3,
		ePARTICLEOUT_MAX = 4,
	};
}
