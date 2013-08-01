#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__TextureCoordinates
	{
	public:
		ADD_STRUCT(float, VL, 12)
		ADD_STRUCT(float, UL, 8)
		ADD_STRUCT(float, V, 4)
		ADD_STRUCT(float, U, 0)
	};
}
#undef ADD_STRUCT
