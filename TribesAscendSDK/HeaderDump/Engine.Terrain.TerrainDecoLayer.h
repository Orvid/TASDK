#pragma once
namespace UnrealScript
{
	struct Terrain__TerrainDecoLayer;
}
#include "Engine.Terrain.TerrainDecoration.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Terrain__TerrainDecoLayer
	{
	public:
		ADD_STRUCT(ScriptArray<Terrain__TerrainDecoration>, Decorations, 12)
		ADD_STRUCT(int, AlphaMapIndex, 24)
		ADD_STRUCT(ScriptString*, Name, 0)
	};
}
#undef ADD_STRUCT
