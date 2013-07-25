#pragma once
#include "Engine.AnimNotify_Scripted.h"
#include "Engine.Actor.h"
#include "Engine.AnimNodeSequence.h"
namespace UnrealScript
{
	class AnimNotify_PawnMaterialParam : public AnimNotify_Scripted
	{
	public:
		void Notify(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify_PawnMaterialParam.Notify");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)(params + 4) = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}