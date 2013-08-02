#pragma once
namespace UnrealScript
{
	class TrEmitCameraEffect_Leaves;
}
#include "TribesGame.TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Leaves : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87262);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
