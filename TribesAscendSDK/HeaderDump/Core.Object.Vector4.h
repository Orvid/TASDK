#pragma once
namespace UnrealScript
{
	struct Object__Vector4;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Vector4
	{
	public:
		ADD_STRUCT(float, X, 0)
		ADD_STRUCT(float, Y, 4)
		ADD_STRUCT(float, Z, 8)
		ADD_STRUCT(float, W, 12)
	};
}
#undef ADD_STRUCT
