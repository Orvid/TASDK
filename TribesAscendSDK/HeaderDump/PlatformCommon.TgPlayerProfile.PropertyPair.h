#pragma once
namespace UnrealScript
{
	struct TgPlayerProfile__PropertyPair;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TgPlayerProfile__PropertyPair
	{
	public:
		ADD_STRUCT(int, Value, 4)
		ADD_STRUCT(int, PropertyId, 0)
	};
}
#undef ADD_STRUCT
