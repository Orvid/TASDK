#pragma once
namespace UnrealScript
{
	class TerrainWeightMapTexture;
}
#include "Core.Object.Pointer.h"
#include "Engine.Terrain.h"
#include "Engine.TerrainWeightMapTexture.TerrainWeightedMaterial.h"
#include "Engine.Texture2D.h"
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
	class TerrainWeightMapTexture : public Texture2D
	{
	public:
		typedef TerrainWeightMapTexture__TerrainWeightedMaterial TerrainWeightedMaterial;
		ADD_STRUCT(ScriptArray<Object__Pointer>, WeightedMaterials, 372)
		ADD_OBJECT(Terrain, ParentTerrain, 368)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
