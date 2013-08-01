#pragma once
#include "Core.Object.h"
#include "Engine.SoundMode.AudioEQEffect.h"
#include "Engine.SoundMode.SoundClassAdjuster.h"
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
	class SoundMode : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<SoundMode__SoundClassAdjuster>, SoundClassEffects, 100)
		ADD_STRUCT(float, FadeOutTime, 124)
		ADD_STRUCT(float, Duration, 120)
		ADD_STRUCT(float, FadeInTime, 116)
		ADD_STRUCT(float, InitialDelay, 112)
		ADD_STRUCT(SoundMode__AudioEQEffect, EQSettings, 64)
		ADD_BOOL(bApplyEQ, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
