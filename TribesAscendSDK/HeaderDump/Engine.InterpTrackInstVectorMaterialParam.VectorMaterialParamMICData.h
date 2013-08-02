#pragma once
namespace UnrealScript
{
	struct InterpTrackInstVectorMaterialParam__VectorMaterialParamMICData;
}
#include "Engine.MaterialInstanceConstant.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackInstVectorMaterialParam__VectorMaterialParamMICData
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, MICs, 0)
		ADD_STRUCT(ScriptArray<Vector>, MICResetVectors, 12)
	};
}
#undef ADD_STRUCT
