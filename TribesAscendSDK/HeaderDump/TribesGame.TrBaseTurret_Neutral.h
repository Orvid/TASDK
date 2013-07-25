#pragma once
#include "TribesGame.TrDeployable_BaseTurret.h"
#include "Engine.Texture2D.h"
namespace UnrealScript
{
	class TrBaseTurret_Neutral : public TrDeployable_BaseTurret
	{
	public:
		bool ShouldShowHelpText(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBaseTurret_Neutral.ShouldShowHelpText");
			byte* params = (byte*)malloc(5);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBaseTurret_Neutral.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}