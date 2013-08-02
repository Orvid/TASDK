#pragma once
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace_Player;
}
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrAnimNodeTurnInPlace_Player.TIP_Transition.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace_Player : public AnimNodeSequence
	{
	public:
		typedef TrAnimNodeTurnInPlace_Player__TIP_Transition TIP_Transition;
		ADD_STRUCT(ScriptArray<TrAnimNodeTurnInPlace_Player__TIP_Transition>, TIP_Transitions, 320)
	};
}
#undef ADD_STRUCT
