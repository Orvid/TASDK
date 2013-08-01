#pragma once
#include "GameFramework.GameTypes.EShakeParam.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameTypes__ShakeParams
	{
	public:
		ADD_STRUCT(GameTypes__EShakeParam, X, 0)
		ADD_STRUCT(GameTypes__EShakeParam, Y, 1)
		ADD_STRUCT(GameTypes__EShakeParam, Z, 2)
		ADD_STRUCT(byte, Padding, 3)
	};
}
#undef ADD_STRUCT
