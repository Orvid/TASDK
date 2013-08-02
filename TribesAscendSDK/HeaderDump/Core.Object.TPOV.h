#pragma once
namespace UnrealScript
{
	struct Object__TPOV;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__TPOV
	{
	public:
		ADD_STRUCT(Vector, Location, 0)
		ADD_STRUCT(Rotator, Rotation, 12)
		ADD_STRUCT(float, FOV, 24)
	};
}
#undef ADD_STRUCT
