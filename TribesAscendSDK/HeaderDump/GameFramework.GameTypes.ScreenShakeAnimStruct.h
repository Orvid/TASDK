#pragma once
#include "Engine.CameraAnim.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct GameTypes__ScreenShakeAnimStruct
	{
	public:
		ADD_OBJECT(CameraAnim, Anim, 0)
		ADD_BOOL(bUseDirectionalAnimVariants, 4, 0x1)
		ADD_OBJECT(CameraAnim, Anim_Left, 8)
		ADD_OBJECT(CameraAnim, Anim_Right, 12)
		ADD_OBJECT(CameraAnim, Anim_Rear, 16)
		ADD_STRUCT(float, AnimPlayRate, 20)
		ADD_STRUCT(float, AnimScale, 24)
		ADD_STRUCT(float, AnimBlendInTime, 28)
		ADD_STRUCT(float, AnimBlendOutTime, 32)
		ADD_BOOL(bRandomSegment, 36, 0x1)
		ADD_STRUCT(float, RandomSegmentDuration, 40)
		ADD_BOOL(bSingleInstance, 44, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
