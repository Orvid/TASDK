#pragma once
#include "Core.Object.LinearColor.h"
#include "Engine.InterpTrackInstProperty.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstLinearColorProp : public InterpTrackInstProperty
	{
	public:
		ADD_STRUCT(Object__LinearColor, ResetColor, 72)
		ADD_STRUCT(Object__Pointer, ColorProp, 68)
	};
}
#undef ADD_STRUCT
