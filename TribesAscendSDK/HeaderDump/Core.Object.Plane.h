#pragma once
namespace UnrealScript
{
	struct Object__Plane;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__Plane : public Vector
	{
	public:
		ADD_STRUCT(float, W, 12)
	};
}
#undef ADD_STRUCT
