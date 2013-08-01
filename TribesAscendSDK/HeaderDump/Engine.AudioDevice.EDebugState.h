#pragma once
namespace UnrealScript
{
	enum AudioDevice__EDebugState : byte
	{
		DEBUGSTATE_None = 0,
		DEBUGSTATE_IsolateDryAudio = 1,
		DEBUGSTATE_IsolateReverb = 2,
		DEBUGSTATE_TestLPF = 3,
		DEBUGSTATE_TestStereoBleed = 4,
		DEBUGSTATE_TestLFEBleed = 5,
		DEBUGSTATE_DisableLPF = 6,
		DEBUGSTATE_DisableRadio = 7,
		DEBUGSTATE_MAX = 8,
	};
}
