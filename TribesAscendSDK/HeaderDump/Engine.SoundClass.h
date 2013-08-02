#pragma once
namespace UnrealScript
{
	class SoundClass;
}
#include "Core.Object.h"
#include "Engine.SoundClass.SoundClassEditorData.h"
#include "Engine.SoundClass.SoundClassProperties.h"
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
	class SoundClass : public Object
	{
	public:
		typedef SoundClass__SoundClassEditorData SoundClassEditorData;
		typedef SoundClass__SoundClassProperties SoundClassProperties;
		ADD_STRUCT(ScriptArray<ScriptName>, ChildClassNames, 92)
		ADD_STRUCT(int, MenuID, 108)
		ADD_BOOL(bIsChild, 104, 0x1)
		ADD_STRUCT(SoundClass__SoundClassProperties, Properties, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
