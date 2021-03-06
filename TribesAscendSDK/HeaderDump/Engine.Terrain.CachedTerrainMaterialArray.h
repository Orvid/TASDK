#pragma once
namespace UnrealScript
{
	struct Terrain__CachedTerrainMaterialArray;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Terrain__CachedTerrainMaterialArray
	{
	public:
		ADD_STRUCT(ScriptArray<Object__Pointer>, CachedMaterials, 0)
	};
}
#undef ADD_STRUCT
