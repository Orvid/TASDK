#pragma once
#include "Engine.Info.h"
#include "Engine.Actor.ActorReference.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class CoverGroup : public Info
	{
	public:
		ADD_STRUCT(ScriptArray<Actor__ActorReference>, CoverLinkRefs, 476)
		ADD_STRUCT(float, AutoSelectHeight, 492)
		ADD_STRUCT(float, AutoSelectRadius, 488)
		void EnableGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13102);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13104);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13105);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
