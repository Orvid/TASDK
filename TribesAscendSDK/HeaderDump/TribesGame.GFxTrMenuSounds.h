#pragma once
namespace UnrealScript
{
	class GFxTrMenuSounds;
}
#include "Core.Object.h"
#include "TribesGame.GFxTrMenuSounds.EMenuSound.h"
namespace UnrealScript
{
	class GFxTrMenuSounds : public Object
	{
	public:
		typedef GFxTrMenuSounds__EMenuSound EMenuSound;
		void SoundToolTip(bool bOpened)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56597);
			byte params[4] = { NULL };
			*(bool*)params = bOpened;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundXPGain(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56599);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundSkillType(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56601);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundClassType(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56603);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundPurchaseSkill()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56605);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoundSelectedQueue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56606);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveQueue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56607);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageForward()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56608);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageBack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56609);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassRollover()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56610);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassSelected()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56611);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassLocked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56612);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMenuSound(GFxTrMenuSounds__EMenuSound MenuSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56613);
			byte params[1] = { NULL };
			*(GFxTrMenuSounds__EMenuSound*)params = MenuSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
