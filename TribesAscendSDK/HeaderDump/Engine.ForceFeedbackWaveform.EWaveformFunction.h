#pragma once
namespace UnrealScript
{
	enum ForceFeedbackWaveform__EWaveformFunction : byte
	{
		WF_Constant = 0,
		WF_LinearIncreasing = 1,
		WF_LinearDecreasing = 2,
		WF_Sin0to90 = 3,
		WF_Sin90to180 = 4,
		WF_Sin0to180 = 5,
		WF_Noise = 6,
		WF_MAX = 7,
	};
}
