#pragma once
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerCoords;
}
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpressionTerrainLayerCoords.ETerrainCoordMappingType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerCoords : public MaterialExpression
	{
	public:
		typedef MaterialExpressionTerrainLayerCoords__ETerrainCoordMappingType ETerrainCoordMappingType;
		ADD_STRUCT(float, MappingPanV, 124)
		ADD_STRUCT(float, MappingPanU, 120)
		ADD_STRUCT(float, MappingRotation, 116)
		ADD_STRUCT(float, MappingScale, 112)
		ADD_STRUCT(MaterialExpressionTerrainLayerCoords__ETerrainCoordMappingType, MappingType, 108)
	};
}
#undef ADD_STRUCT
