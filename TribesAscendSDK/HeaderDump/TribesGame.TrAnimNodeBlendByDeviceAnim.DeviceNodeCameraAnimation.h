#pragma once
#include "Engine.CameraAnimInst.h"
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
	struct TrAnimNodeBlendByDeviceAnim__DeviceNodeCameraAnimation
	{
	public:
		ADD_BOOL(bRandomStartTime, 28, 0x2)
		ADD_BOOL(bLoop, 28, 0x1)
		ADD_STRUCT(float, BlendOutTime, 24)
		ADD_STRUCT(float, BlendInTime, 20)
		ADD_STRUCT(float, Scale, 16)
		ADD_STRUCT(float, Rate, 12)
		ADD_OBJECT(CameraAnimInst, CameraAnimInstance, 8)
		ADD_OBJECT(CameraAnim, CameraAnim, 4)
		ADD_STRUCT(int, ChildIndex, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
