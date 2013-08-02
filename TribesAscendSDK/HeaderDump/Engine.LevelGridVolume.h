#pragma once
namespace UnrealScript
{
	class LevelGridVolume;
}
#include "Engine.KMeshProps.KConvexElem.h"
#include "Engine.LevelGridVolume.LevelGridCellCoordinate.h"
#include "Engine.LevelGridVolume.LevelGridCellShape.h"
#include "Engine.Volume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LevelGridVolume : public Volume
	{
	public:
		typedef LevelGridVolume__LevelGridCellShape LevelGridCellShape;
		typedef LevelGridVolume__LevelGridCellCoordinate LevelGridCellCoordinate;
		ADD_STRUCT(KMeshProps__KConvexElem, CellConvexElem, 556)
		ADD_STRUCT(float, KeepLoadedRange, 552)
		ADD_STRUCT(float, LoadingDistance, 548)
		ADD_STRUCT(int, Subdivisions, 536)
		ADD_STRUCT(LevelGridVolume__LevelGridCellShape, CellShape, 532)
		ADD_STRUCT(ScriptString*, LevelGridVolumeName, 520)
	};
}
#undef ADD_STRUCT
