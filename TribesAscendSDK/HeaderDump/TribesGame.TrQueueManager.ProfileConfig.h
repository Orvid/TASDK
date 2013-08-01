#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrQueueManager__ProfileConfig
	{
	public:
		ADD_STRUCT(ScriptString*, PasswordPublic, 48)
		ADD_STRUCT(ScriptString*, PasswordAdmin, 36)
		ADD_STRUCT(ScriptString*, ProfileDesc, 24)
		ADD_STRUCT(ScriptString*, ProfileName, 12)
		ADD_STRUCT(int, QueueCaseId, 8)
		ADD_STRUCT(int, GameCaseId, 4)
		ADD_STRUCT(int, Slots, 0)
	};
}
#undef ADD_STRUCT
