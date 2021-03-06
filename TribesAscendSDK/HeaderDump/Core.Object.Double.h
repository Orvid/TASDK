#pragma once
namespace UnrealScript
{
	struct Object__Double;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Double
	{
	public:
		ADD_STRUCT(int, A, 0)
		ADD_STRUCT(int, B, 4)
	};
}
#undef ADD_STRUCT
