#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Scout__PathSizeInfo
	{
	public:
		ADD_STRUCT(byte, PathColor, 20)
		ADD_STRUCT(float, CrouchHeight, 16)
		ADD_STRUCT(float, Height, 12)
		ADD_STRUCT(float, Radius, 8)
		ADD_STRUCT(ScriptName, Desc, 0)
	};
}
#undef ADD_STRUCT
