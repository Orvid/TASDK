#pragma once
#include "TribesGame.TrObject.CaHCapturePointLabel.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrCaHStats__CapturePointInfo
	{
	public:
		ADD_STRUCT(float, RemainingHeldTime, 24)
		ADD_STRUCT(int, PctHeld, 20)
		ADD_STRUCT(int, PointOwnershipType, 16)
		ADD_STRUCT(ScriptString*, LabelString, 4)
		ADD_STRUCT(TrObject__CaHCapturePointLabel, PointLabel, 0)
	};
}
#undef ADD_STRUCT
