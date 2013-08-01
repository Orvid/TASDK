#pragma once
#include "Engine.FontImportOptions.EFontImportCharacterSet.h"
#include "Core.Object.LinearColor.h"
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
	struct FontImportOptions__FontImportOptionsData
	{
	public:
		ADD_STRUCT(ScriptString*, FontName, 0)
		ADD_STRUCT(float, Height, 12)
		ADD_BOOL(bEnableAntialiasing, 16, 0x1)
		ADD_BOOL(bEnableBold, 16, 0x2)
		ADD_BOOL(bEnableItalic, 16, 0x4)
		ADD_BOOL(bEnableUnderline, 16, 0x8)
		ADD_BOOL(bAlphaOnly, 16, 0x10)
		ADD_STRUCT(FontImportOptions__EFontImportCharacterSet, CharacterSet, 20)
		ADD_STRUCT(ScriptString*, Chars, 24)
		ADD_STRUCT(ScriptString*, UnicodeRange, 36)
		ADD_STRUCT(ScriptString*, CharsFilePath, 48)
		ADD_STRUCT(ScriptString*, CharsFileWildcard, 60)
		ADD_BOOL(bCreatePrintableOnly, 72, 0x1)
		ADD_BOOL(bIncludeASCIIRange, 72, 0x2)
		ADD_STRUCT(Object__LinearColor, ForegroundColor, 76)
		ADD_BOOL(bEnableDropShadow, 92, 0x1)
		ADD_STRUCT(int, TexturePageWidth, 96)
		ADD_STRUCT(int, TexturePageMaxHeight, 100)
		ADD_STRUCT(int, XPadding, 104)
		ADD_STRUCT(int, YPadding, 108)
		ADD_STRUCT(int, ExtendBoxTop, 112)
		ADD_STRUCT(int, ExtendBoxBottom, 116)
		ADD_STRUCT(int, ExtendBoxRight, 120)
		ADD_STRUCT(int, ExtendBoxLeft, 124)
		ADD_BOOL(bEnableLegacyMode, 128, 0x1)
		ADD_STRUCT(int, Kerning, 132)
		ADD_BOOL(bUseDistanceFieldAlpha, 136, 0x1)
		ADD_STRUCT(int, DistanceFieldScaleFactor, 140)
		ADD_STRUCT(float, DistanceFieldScanRadiusScale, 144)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
