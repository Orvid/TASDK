#pragma once
#include "Engine.OnlineGameSearch.EOnlineGameSearchEntryType.h"
#include "Engine.OnlineGameSearch.EOnlineGameSearchComparisonType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameSearch__OnlineGameSearchParameter
	{
	public:
		ADD_STRUCT(int, EntryId, 0)
		ADD_STRUCT(ScriptName, ObjectPropertyName, 4)
		ADD_STRUCT(OnlineGameSearch__EOnlineGameSearchEntryType, EntryType, 12)
		ADD_STRUCT(OnlineGameSearch__EOnlineGameSearchComparisonType, ComparisonType, 13)
	};
}
#undef ADD_STRUCT
