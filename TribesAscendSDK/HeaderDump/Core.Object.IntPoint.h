#pragma once
namespace UnrealScript
{
	struct Object__IntPoint;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__IntPoint
	{
	public:
		ADD_STRUCT(int, X, 0)
		ADD_STRUCT(int, Y, 4)
	};
}
#undef ADD_STRUCT
