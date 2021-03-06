#pragma once
namespace UnrealScript
{
	class TrBaseTurret_Neutral;
}
#include "Engine.Texture2D.h"
#include "TribesGame.TrDeployable_BaseTurret.h"
#include "TribesGame.TrHelpTextManager.EHelpTextType.h"
namespace UnrealScript
{
	class TrBaseTurret_Neutral : public TrDeployable_BaseTurret
	{
	public:
		bool ShouldShowHelpText(TrHelpTextManager__EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72148);
			byte params[5] = { NULL };
			*(TrHelpTextManager__EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72151);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
