#pragma once
namespace UnrealScript
{
	struct GameplayEvents__GameplayEventsHeader;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__GameplayEventsHeader
	{
	public:
		ADD_STRUCT(int, Flags, 40)
		ADD_STRUCT(ScriptString*, FilterClass, 28)
		ADD_STRUCT(int, FileSize, 24)
		ADD_STRUCT(int, TotalStreamSize, 20)
		ADD_STRUCT(int, FooterOffset, 16)
		ADD_STRUCT(int, AggregateOffset, 12)
		ADD_STRUCT(int, StreamOffset, 8)
		ADD_STRUCT(int, StatsWriterVersion, 4)
		ADD_STRUCT(int, EngineVersion, 0)
	};
}
#undef ADD_STRUCT
