#pragma once
namespace UnrealScript
{
	class InterpTrackInstVectorMaterialParam;
}
#include "Engine.InterpTrackInst.h"
#include "Engine.InterpTrackInstVectorMaterialParam.VectorMaterialParamMICData.h"
#include "Engine.InterpTrackVectorMaterialParam.h"
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
	class InterpTrackInstVectorMaterialParam : public InterpTrackInst
	{
	public:
		typedef InterpTrackInstVectorMaterialParam__VectorMaterialParamMICData VectorMaterialParamMICData;
		ADD_STRUCT(ScriptArray<InterpTrackInstVectorMaterialParam__VectorMaterialParamMICData>, MICInfos, 60)
		ADD_OBJECT(InterpTrackVectorMaterialParam, InstancedTrack, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
