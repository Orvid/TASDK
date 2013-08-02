#pragma once
namespace UnrealScript
{
	struct TrQueueManager__ServerInfo;
}
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrQueueManager__ServerInfo
	{
	public:
		ADD_STRUCT(int, PlayerCount, 20)
		ADD_STRUCT(int, PlayerMax, 16)
		ADD_STRUCT(ScriptString*, MapName, 56)
		ADD_STRUCT(ScriptString*, ServerName, 32)
		ADD_BOOL(bFavorite, 24, 0x2)
		ADD_STRUCT(int, queueId, 4)
		ADD_STRUCT(int, Ping, 0)
		ADD_BOOL(bPrivate, 24, 0x1)
		ADD_STRUCT(ScriptString*, Ruleset, 68)
		ADD_STRUCT(int, MinLevel, 8)
		ADD_STRUCT(int, MaxLevel, 12)
		ADD_STRUCT(ScriptString*, ServerDesc, 44)
		ADD_STRUCT(int, GameType, 28)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
