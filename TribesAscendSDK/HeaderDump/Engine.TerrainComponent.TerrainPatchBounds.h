#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TerrainComponent__TerrainPatchBounds
	{
	public:
		ADD_STRUCT(float, MaxDisplacement, 8)
		ADD_STRUCT(float, MaxHeight, 4)
		ADD_STRUCT(float, MinHeight, 0)
	};
}
#undef ADD_STRUCT
