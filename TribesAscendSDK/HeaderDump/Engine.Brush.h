#pragma once
namespace UnrealScript
{
	class Brush;
}
#include "Core.Object.Color.h"
#include "Engine.Actor.h"
#include "Engine.Brush.ECsgOper.h"
#include "Engine.Brush.GeomSelection.h"
#include "Engine.Model.h"
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
	class Brush : public Actor
	{
	public:
		typedef Brush__ECsgOper ECsgOper;
		typedef Brush__GeomSelection GeomSelection;
		ADD_STRUCT(ScriptArray<Brush__GeomSelection>, SavedSelections, 500)
		ADD_BOOL(bPlaceableFromClassBrowser, 488, 0x4)
		ADD_BOOL(bSolidWhenSelected, 488, 0x2)
		ADD_BOOL(bColored, 488, 0x1)
		ADD_STRUCT(int, PolyFlags, 484)
		ADD_STRUCT(Object__Color, BrushColor, 480)
		ADD_STRUCT(Brush__ECsgOper, CsgOper, 476)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
