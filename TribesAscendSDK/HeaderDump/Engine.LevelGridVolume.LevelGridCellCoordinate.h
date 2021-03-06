#pragma once
namespace UnrealScript
{
	struct LevelGridVolume__LevelGridCellCoordinate;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct LevelGridVolume__LevelGridCellCoordinate
	{
	public:
		ADD_STRUCT(int, Z, 8)
		ADD_STRUCT(int, Y, 4)
		ADD_STRUCT(int, X, 0)
	};
}
#undef ADD_STRUCT
