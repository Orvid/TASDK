#pragma once
namespace UnrealScript
{
	struct GFxMoviePlayer__GFxDataStoreBinding;
}
#include "Core.Object.Pointer.h"
#include "Engine.UIRoot.UIDataStoreBinding.h"
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
	struct GFxMoviePlayer__GFxDataStoreBinding
	{
	public:
		ADD_STRUCT(UIRoot__UIDataStoreBinding, DataSource, 0)
		ADD_STRUCT(ScriptString*, VarPath, 48)
		ADD_STRUCT(ScriptString*, ModelId, 60)
		ADD_STRUCT(ScriptString*, ControlId, 72)
		ADD_BOOL(bEditable, 84, 0x1)
		ADD_STRUCT(ScriptArray<ScriptName>, CellTags, 88)
		ADD_STRUCT(ScriptArray<byte>, ModelIdUtf8, 100)
		ADD_STRUCT(ScriptArray<byte>, ControlIdUtf8, 112)
		ADD_STRUCT(ScriptArray<ScriptName>, FullCellTags, 132)
		ADD_STRUCT(Object__Pointer, ModelRef, 144)
		ADD_STRUCT(Object__Pointer, ControlRef, 148)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
