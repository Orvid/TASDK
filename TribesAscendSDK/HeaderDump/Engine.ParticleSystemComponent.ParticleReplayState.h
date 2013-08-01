#pragma once
namespace UnrealScript
{
	enum ParticleSystemComponent__ParticleReplayState : byte
	{
		PRS_Disabled = 0,
		PRS_Capturing = 1,
		PRS_Replaying = 2,
		PRS_MAX = 3,
	};
}
