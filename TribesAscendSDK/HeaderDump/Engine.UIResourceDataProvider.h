#pragma once
namespace UnrealScript
{
	class UIResourceDataProvider;
}
#include "Core.Object.Pointer.h"
#include "Engine.UIPropertyDataProvider.h"
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
	class UIResourceDataProvider : public UIPropertyDataProvider
	{
	public:
		ADD_BOOL(bSkipDuringEnumeration, 120, 0x2)
		ADD_BOOL(bDataBindingPropertiesOnly, 120, 0x1)
		ADD_STRUCT(Object__Pointer, VfTable_IUIListElementCellProvider, 116)
		ADD_STRUCT(Object__Pointer, VfTable_IUIListElementProvider, 112)
		void InitializeProvider(bool bIsEditor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22607);
			byte params[4] = { NULL };
			*(bool*)params = bIsEditor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
