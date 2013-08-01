#pragma once
#include "Engine.OnlineGameSearch.OnlineGameSearchParameter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameSearch__OnlineGameSearchORClause
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineGameSearch__OnlineGameSearchParameter>, OrParams, 0)
	};
}
#undef ADD_STRUCT
