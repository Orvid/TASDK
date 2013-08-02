#pragma once
namespace UnrealScript
{
	struct Object__SHVector;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__SHVector
	{
	public:
		ADD_STRUCT(float, V, 0)
		ADD_STRUCT(float, Padding, 36)
	};
}
#undef ADD_STRUCT
