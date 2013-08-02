#pragma once
namespace UnrealScript
{
	struct LocalPlayer__PostProcessSettingsOverride;
}
#include "Engine.PostProcessVolume.PostProcessSettings.h"
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
	struct LocalPlayer__PostProcessSettingsOverride
	{
	public:
		ADD_STRUCT(float, BlendStartTime, 240)
		ADD_STRUCT(float, BlendOutDuration, 236)
		ADD_STRUCT(float, BlendInDuration, 232)
		ADD_STRUCT(float, CurrentBlendOutTime, 228)
		ADD_STRUCT(float, CurrentBlendInTime, 224)
		ADD_BOOL(bBlendingOut, 220, 0x2)
		ADD_BOOL(bBlendingIn, 220, 0x1)
		ADD_STRUCT(PostProcessVolume__PostProcessSettings, Settings, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
