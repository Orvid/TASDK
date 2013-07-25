#pragma once
#include "Engine__SequenceCondition.h"
namespace UnrealScript
{
	class SeqCond_IsBenchmarking : public SequenceCondition
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqCond_IsBenchmarking.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
