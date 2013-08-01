#pragma once
namespace UnrealScript
{
	enum Object__EInterpMethodType : byte
	{
		IMT_UseFixedTangentEvalAndNewAutoTangents = 0,
		IMT_UseFixedTangentEval = 1,
		IMT_UseBrokenTangentEval = 2,
		IMT_MAX = 3,
	};
}
