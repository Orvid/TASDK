#pragma once
namespace UnrealScript
{
	class SeqEvent_MobileSwipe;
}
#include "Core.Object.Vector2D.h"
#include "GameFramework.SeqEvent_MobileRawInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileSwipe : public SeqEvent_MobileRawInput
	{
	public:
		ADD_STRUCT(Object__Vector2D, InitialTouch, 280)
		ADD_STRUCT(float, MinDistance, 276)
		ADD_STRUCT(float, Tolerance, 272)
	};
}
#undef ADD_STRUCT
