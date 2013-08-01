#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Terrain__SelectedTerrainVertex
	{
	public:
		ADD_STRUCT(int, Weight, 8)
		ADD_STRUCT(int, Y, 4)
		ADD_STRUCT(int, X, 0)
	};
}
#undef ADD_STRUCT
