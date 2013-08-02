#pragma once
namespace UnrealScript
{
	class InterpTrackInstFloatMaterialParam;
}
#include "Engine.InterpTrackFloatMaterialParam.h"
#include "Engine.InterpTrackInst.h"
#include "Engine.InterpTrackInstFloatMaterialParam.FloatMaterialParamMICData.h"
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
	class InterpTrackInstFloatMaterialParam : public InterpTrackInst
	{
	public:
		typedef InterpTrackInstFloatMaterialParam__FloatMaterialParamMICData FloatMaterialParamMICData;
		ADD_STRUCT(ScriptArray<InterpTrackInstFloatMaterialParam__FloatMaterialParamMICData>, MICInfos, 60)
		ADD_OBJECT(InterpTrackFloatMaterialParam, InstancedTrack, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
