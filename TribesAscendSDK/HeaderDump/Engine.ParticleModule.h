#pragma once
#include "Core.Object.h"
#include "Core.Object.Color.h"
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
	class ParticleModule : public Object
	{
	public:
		ADD_STRUCT(Object__Color, ModuleEditorColor, 68)
		ADD_STRUCT(byte, LODValidity, 64)
		ADD_BOOL(bRequiresLoopingNotification, 60, 0x400)
		ADD_BOOL(bSupportsRandomSeed, 60, 0x200)
		ADD_BOOL(LODDuplicate, 60, 0x100)
		ADD_BOOL(bEditable, 60, 0x80)
		ADD_BOOL(bEnabled, 60, 0x40)
		ADD_BOOL(bSupported3DDrawMode, 60, 0x20)
		ADD_BOOL(b3DDrawMode, 60, 0x10)
		ADD_BOOL(bCurvesAsColor, 60, 0x8)
		ADD_BOOL(bFinalUpdateModule, 60, 0x4)
		ADD_BOOL(bUpdateModule, 60, 0x2)
		ADD_BOOL(bSpawnModule, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
