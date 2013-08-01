#pragma once
#include "Engine.SkelControlBase.h"
#include "Engine.SkelControlSpline.ESplineControlRotMode.h"
#include "Core.Object.EAxis.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkelControlSpline : public SkelControlBase
	{
	public:
		ADD_STRUCT(float, StartSplineTension, 204)
		ADD_STRUCT(float, EndSplineTension, 200)
		ADD_BOOL(bInvertSplineBoneAxis, 196, 0x1)
		ADD_STRUCT(SkelControlSpline__ESplineControlRotMode, BoneRotMode, 193)
		ADD_STRUCT(int, SplineLength, 188)
		ADD_STRUCT(Object__EAxis, SplineBoneAxis, 192)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
