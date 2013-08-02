#pragma once
namespace UnrealScript
{
	struct Object__BoxSphereBounds;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__BoxSphereBounds
	{
	public:
		ADD_STRUCT(Vector, Origin, 0)
		ADD_STRUCT(Vector, BoxExtent, 12)
		ADD_STRUCT(float, SphereRadius, 24)
	};
}
#undef ADD_STRUCT
