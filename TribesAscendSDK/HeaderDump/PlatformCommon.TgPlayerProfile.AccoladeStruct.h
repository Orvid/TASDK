#pragma once
namespace UnrealScript
{
	struct TgPlayerProfile__AccoladeStruct;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TgPlayerProfile__AccoladeStruct
	{
	public:
		ADD_STRUCT(int, Value, 12)
		ADD_STRUCT(int, Type, 8)
		ADD_STRUCT(int, ActivityId, 4)
		ADD_STRUCT(int, AccoladeId, 0)
	};
}
#undef ADD_STRUCT
