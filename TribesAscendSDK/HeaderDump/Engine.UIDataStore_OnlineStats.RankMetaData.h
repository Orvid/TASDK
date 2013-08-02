#pragma once
namespace UnrealScript
{
	struct UIDataStore_OnlineStats__RankMetaData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataStore_OnlineStats__RankMetaData
	{
	public:
		ADD_STRUCT(ScriptString*, RankColumnName, 8)
		ADD_STRUCT(ScriptName, RankName, 0)
	};
}
#undef ADD_STRUCT
