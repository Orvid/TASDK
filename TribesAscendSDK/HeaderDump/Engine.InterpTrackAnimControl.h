#pragma once
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.AnimSet.h"
#include "Engine.InterpTrackAnimControl.AnimControlTrackKey.h"
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
	class InterpTrackAnimControl : public InterpTrackFloatBase
	{
	public:
		ADD_STRUCT(ScriptArray<class AnimSet*>, AnimSets, 148)
		ADD_STRUCT(ScriptArray<InterpTrackAnimControl__AnimControlTrackKey>, AnimSeqs, 168)
		ADD_BOOL(bEnableRootMotion, 180, 0x1)
		ADD_STRUCT(ScriptName, SlotName, 160)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
