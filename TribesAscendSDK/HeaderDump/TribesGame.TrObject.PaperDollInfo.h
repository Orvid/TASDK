#pragma once
namespace UnrealScript
{
	struct TrObject__PaperDollInfo;
}
#include "Engine.AnimSet.h"
#include "Engine.AnimTree.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.SkeletalMesh.h"
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
	struct TrObject__PaperDollInfo
	{
	public:
		ADD_BOOL(bIsLoading, 52, 0x2)
		ADD_BOOL(bIsStreaming, 52, 0x1)
		ADD_STRUCT(float, CharacterLightingContrastFactor, 48)
		ADD_BOOL(bOnlySelfShadow, 44, 0x1)
		ADD_OBJECT(AnimSet, AnimSet, 40)
		ADD_OBJECT(AnimTree, AnimTreeTemplate, 36)
		ADD_OBJECT(PhysicsAsset, PhysAsset, 32)
		ADD_OBJECT(SkeletalMesh, SkelMesh, 28)
		ADD_STRUCT(float, Scale, 24)
		ADD_STRUCT(Rotator, Rotation, 12)
		ADD_STRUCT(Vector, Translation, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
