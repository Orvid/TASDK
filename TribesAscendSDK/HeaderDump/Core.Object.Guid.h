#pragma once
namespace UnrealScript
{
	struct Object__Guid;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Guid
	{
	public:
		ADD_STRUCT(int, A, 0)
		ADD_STRUCT(int, B, 4)
		ADD_STRUCT(int, C, 8)
		ADD_STRUCT(int, D, 12)
	};
}
#undef ADD_STRUCT
