#pragma once
namespace UnrealScript
{
	class DOFEffect;
}
#include "Core.Object.Color.h"
#include "Engine.DOFEffect.EFocusType.h"
#include "Engine.PostProcessEffect.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DOFEffect : public PostProcessEffect
	{
	public:
		typedef DOFEffect__EFocusType EFocusType;
		ADD_STRUCT(float, FalloffExponent, 100)
		ADD_STRUCT(float, BlurKernelSize, 104)
		ADD_STRUCT(float, MaxNearBlurAmount, 108)
		ADD_STRUCT(float, MinBlurAmount, 112)
		ADD_STRUCT(float, MaxFarBlurAmount, 116)
		ADD_STRUCT(Object__Color, ModulateBlurColor, 120)
		ADD_STRUCT(DOFEffect__EFocusType, FocusType, 124)
		ADD_STRUCT(float, FocusInnerRadius, 128)
		ADD_STRUCT(float, FocusDistance, 132)
		ADD_STRUCT(Vector, FocusPosition, 136)
	};
}
#undef ADD_STRUCT
