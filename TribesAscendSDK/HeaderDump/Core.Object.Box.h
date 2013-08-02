#pragma once
namespace UnrealScript
{
	struct Object__Box;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Box
	{
	public:
		ADD_STRUCT(Vector, Min, 0)
		ADD_STRUCT(Vector, Max, 12)
		ADD_STRUCT(byte, IsValid, 24)
	};
}
#undef ADD_STRUCT
