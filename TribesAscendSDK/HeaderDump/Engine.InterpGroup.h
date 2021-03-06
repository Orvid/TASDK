#pragma once
namespace UnrealScript
{
	class InterpGroup;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Core.Object.Pointer.h"
#include "Engine.AnimSet.h"
#include "Engine.InterpGroup.InterpEdSelKey.h"
#include "Engine.InterpTrack.h"
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
	class InterpGroup : public Object
	{
	public:
		typedef InterpGroup__InterpEdSelKey InterpEdSelKey;
		ADD_STRUCT(ScriptArray<class InterpTrack*>, InterpTracks, 64)
		ADD_STRUCT(ScriptArray<class AnimSet*>, GroupAnimSets, 88)
		ADD_BOOL(bIsSelected, 100, 0x10)
		ADD_BOOL(bIsParented, 100, 0x8)
		ADD_BOOL(bIsFolder, 100, 0x4)
		ADD_BOOL(bVisible, 100, 0x2)
		ADD_BOOL(bCollapsed, 100, 0x1)
		ADD_STRUCT(Object__Color, GroupColor, 84)
		ADD_STRUCT(ScriptName, GroupName, 76)
		ADD_STRUCT(Object__Pointer, VfTable_FInterpEdInputInterface, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
