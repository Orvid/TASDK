#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Terrain__TerrainDecorationInstance
	{
	public:
		ADD_STRUCT(int, Yaw, 16)
		ADD_STRUCT(float, Scale, 12)
		ADD_STRUCT(float, Y, 8)
		ADD_STRUCT(float, X, 4)
	};
}
#undef ADD_STRUCT
