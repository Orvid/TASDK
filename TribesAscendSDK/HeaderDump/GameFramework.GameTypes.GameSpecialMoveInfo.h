#pragma once
namespace UnrealScript
{
	struct GameTypes__GameSpecialMoveInfo;
}
#include "GameFramework.GameSpecialMove.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct GameTypes__GameSpecialMoveInfo
	{
	public:
		ADD_STRUCT(ScriptName, SpecialMoveName, 0)
		ADD_OBJECT(ScriptClass, SpecialMoveClass, 8)
		ADD_OBJECT(GameSpecialMove, SpecialMoveInstance, 12)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
