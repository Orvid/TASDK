#pragma once
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.PostProcessVolume.h"
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
	struct LocalPlayer__CurrentPostProcessVolumeInfo
	{
	public:
		ADD_STRUCT(float, LastBlendTime, 228)
		ADD_STRUCT(float, BlendStartTime, 224)
		ADD_OBJECT(PostProcessVolume, LastVolumeUsed, 220)
		ADD_STRUCT(PostProcessVolume__PostProcessSettings, LastSettings, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
