#pragma once
namespace UnrealScript
{
	struct Object__TwoVectors;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__TwoVectors
	{
	public:
		ADD_STRUCT(Vector, v1, 0)
		ADD_STRUCT(Vector, v2, 12)
	};
}
#undef ADD_STRUCT
