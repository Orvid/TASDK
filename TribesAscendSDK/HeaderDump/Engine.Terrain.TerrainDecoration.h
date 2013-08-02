#pragma once
namespace UnrealScript
{
	struct Terrain__TerrainDecoration;
}
#include "Engine.PrimitiveComponentFactory.h"
#include "Engine.Terrain.TerrainDecorationInstance.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct Terrain__TerrainDecoration
	{
	public:
		ADD_STRUCT(ScriptArray<Terrain__TerrainDecorationInstance>, Instances, 24)
		ADD_STRUCT(int, RandSeed, 20)
		ADD_STRUCT(float, SlopeRotationBlend, 16)
		ADD_STRUCT(float, Density, 12)
		ADD_STRUCT(float, MaxScale, 8)
		ADD_STRUCT(float, MinScale, 4)
		ADD_OBJECT(PrimitiveComponentFactory, Factory, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
