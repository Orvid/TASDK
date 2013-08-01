#pragma once
#include "Engine.OnlineGameSearch.OnlineGameSearchORClause.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchSortClause.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameSearch__OnlineGameSearchQuery
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineGameSearch__OnlineGameSearchORClause>, OrClauses, 0)
		ADD_STRUCT(ScriptArray<OnlineGameSearch__OnlineGameSearchSortClause>, SortClauses, 12)
	};
}
#undef ADD_STRUCT
