#pragma once
namespace UnrealScript
{
	class InterpTrackLinearColorBase;
}
#include "Core.Object.InterpCurveLinearColor.h"
#include "Engine.InterpTrack.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackLinearColorBase : public InterpTrack
	{
	public:
		ADD_STRUCT(float, CurveTension, 144)
		ADD_STRUCT(Object__InterpCurveLinearColor, LinearColorTrack, 128)
	};
}
#undef ADD_STRUCT
