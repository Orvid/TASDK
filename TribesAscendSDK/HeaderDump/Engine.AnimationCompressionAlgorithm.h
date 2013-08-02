#pragma once
namespace UnrealScript
{
	class AnimationCompressionAlgorithm;
}
#include "Core.Object.h"
#include "Engine.AnimSequence.AnimationCompressionFormat.h"
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
	class AnimationCompressionAlgorithm : public Object
	{
	public:
		ADD_STRUCT(AnimSequence__AnimationCompressionFormat, RotationCompressionFormat, 77)
		ADD_STRUCT(AnimSequence__AnimationCompressionFormat, TranslationCompressionFormat, 76)
		ADD_BOOL(bNeedsSkeleton, 72, 0x1)
		ADD_STRUCT(ScriptString*, Description, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
