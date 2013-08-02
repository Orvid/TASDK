#pragma once
namespace UnrealScript
{
	struct OnlineStatsRead__ColumnMetaData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineStatsRead__ColumnMetaData
	{
	public:
		ADD_STRUCT(ScriptString*, ColumnName, 12)
		ADD_STRUCT(ScriptName, Name, 4)
		ADD_STRUCT(int, Id, 0)
	};
}
#undef ADD_STRUCT
