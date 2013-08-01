#pragma once
#include "Engine.EngineTypes.SubtitleCue.h"
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
	struct EngineTypes__LocalizedSubtitle
	{
	public:
		ADD_STRUCT(ScriptArray<EngineTypes__SubtitleCue>, Subtitles, 12)
		ADD_BOOL(bManualWordWrap, 24, 0x2)
		ADD_BOOL(bMature, 24, 0x1)
		ADD_STRUCT(ScriptString*, LanguageExt, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT