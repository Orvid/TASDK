#pragma once
namespace UnrealScript
{
	class FontImportOptions;
}
#include "Core.Object.h"
#include "Engine.FontImportOptions.EFontImportCharacterSet.h"
#include "Engine.FontImportOptions.FontImportOptionsData.h"
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
	class FontImportOptions : public Object
	{
	public:
		typedef FontImportOptions__EFontImportCharacterSet EFontImportCharacterSet;
		typedef FontImportOptions__FontImportOptionsData FontImportOptionsData;
		ADD_STRUCT(FontImportOptions__FontImportOptionsData, Data, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
