#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__LinearColor
	{
	public:
		ADD_STRUCT(float, R, 0)
		ADD_STRUCT(float, G, 4)
		ADD_STRUCT(float, B, 8)
		ADD_STRUCT(float, A, 12)
	};
}
#undef ADD_STRUCT
