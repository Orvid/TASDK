#pragma once
namespace UnrealScript
{
	class AnimNotify_ClothingMaxDistanceScale;
}
#include "Engine.AnimNotify.h"
#include "Engine.SkeletalMeshComponent.EMaxDistanceScaleMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_ClothingMaxDistanceScale : public AnimNotify
	{
	public:
		ADD_STRUCT(float, Duration, 76)
		ADD_STRUCT(SkeletalMeshComponent__EMaxDistanceScaleMode, ScaleMode, 72)
		ADD_STRUCT(float, EndScale, 68)
		ADD_STRUCT(float, StartScale, 64)
	};
}
#undef ADD_STRUCT
