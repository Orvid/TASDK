#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Font__FontCharacter
	{
	public:
		ADD_STRUCT(int, VerticalOffset, 20)
		ADD_STRUCT(byte, TextureIndex, 16)
		ADD_STRUCT(int, VSize, 12)
		ADD_STRUCT(int, USize, 8)
		ADD_STRUCT(int, StartV, 4)
		ADD_STRUCT(int, StartU, 0)
	};
}
#undef ADD_STRUCT
