#pragma once
namespace UnrealScript
{
	class AnimNotify_PawnMaterialParam;
}
#include "Engine.Actor.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.AnimNotify_Scripted.h"
#include "Engine.Pawn.ScalarParameterInterpStruct.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_PawnMaterialParam : public AnimNotify_Scripted
	{
	public:
		ADD_STRUCT(ScriptArray<Pawn__ScalarParameterInterpStruct>, ScalarParameterInterpArray, 64)
		void Notify(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11393);
			byte params[8] = { NULL };
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)&params[4] = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
