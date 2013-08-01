#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TgPlayerProfile__BadgeStruct
	{
	public:
		ADD_STRUCT(ScriptString*, Description, 40)
		ADD_STRUCT(ScriptString*, Title, 28)
		ADD_STRUCT(int, Category, 24)
		ADD_STRUCT(int, MaxValue, 20)
		ADD_STRUCT(int, Progress, 16)
		ADD_STRUCT(int, Tier, 12)
		ADD_STRUCT(int, Icon, 8)
		ADD_STRUCT(int, ActivityId, 4)
		ADD_STRUCT(int, BadgeId, 0)
	};
}
#undef ADD_STRUCT
