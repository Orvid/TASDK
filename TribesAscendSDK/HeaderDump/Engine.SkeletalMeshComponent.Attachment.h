#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMeshComponent__Attachment
	{
	public:
		ADD_STRUCT(ScriptName, BoneName, 4)
		ADD_STRUCT(Vector, RelativeLocation, 12)
		ADD_STRUCT(Rotator, RelativeRotation, 24)
		ADD_STRUCT(Vector, RelativeScale, 36)
	};
}
#undef ADD_STRUCT
