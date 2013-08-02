#pragma once
namespace UnrealScript
{
	struct OnlineStatsRead__OnlineStatsRow;
}
#include "Engine.OnlineStatsRead.OnlineStatsColumn.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Settings.SettingsData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineStatsRead__OnlineStatsRow
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineStatsRead__OnlineStatsColumn>, Columns, 32)
		ADD_STRUCT(ScriptString*, NickName, 20)
		ADD_STRUCT(Settings__SettingsData, Rank, 8)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PlayerID, 0)
	};
}
#undef ADD_STRUCT
