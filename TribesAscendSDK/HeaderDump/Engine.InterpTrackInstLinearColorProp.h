#pragma once
namespace UnrealScript
{
	class InterpTrackInstLinearColorProp;
}
#include "Core.Object.LinearColor.h"
#include "Core.Object.Pointer.h"
#include "Engine.InterpTrackInstProperty.h"
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
