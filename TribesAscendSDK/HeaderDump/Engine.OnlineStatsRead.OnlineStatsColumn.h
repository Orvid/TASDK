#pragma once
namespace UnrealScript
{
	struct OnlineStatsRead__OnlineStatsColumn;
}
#include "Engine.Settings.SettingsData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineStatsRead__OnlineStatsColumn
	{
	public:
		ADD_STRUCT(Settings__SettingsData, StatValue, 4)
		ADD_STRUCT(int, ColumnNo, 0)
	};
}
#undef ADD_STRUCT
