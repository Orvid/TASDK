#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Color
	{
	public:
		ADD_STRUCT(byte, R, 2)
		ADD_STRUCT(byte, G, 1)
		ADD_STRUCT(byte, B, 0)
		ADD_STRUCT(byte, A, 3)
	};
}
#undef ADD_STRUCT
