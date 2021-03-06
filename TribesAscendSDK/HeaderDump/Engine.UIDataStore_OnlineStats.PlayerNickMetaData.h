#pragma once
namespace UnrealScript
{
	struct UIDataStore_OnlineStats__PlayerNickMetaData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataStore_OnlineStats__PlayerNickMetaData
	{
	public:
		ADD_STRUCT(ScriptString*, PlayerNickColumnName, 8)
		ADD_STRUCT(ScriptName, PlayerNickName, 0)
	};
}
#undef ADD_STRUCT
