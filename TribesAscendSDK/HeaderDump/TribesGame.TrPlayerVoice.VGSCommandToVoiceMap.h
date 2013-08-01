#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrVGSCommandList.VGSCommandType.h"
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
	struct TrPlayerVoice__VGSCommandToVoiceMap
	{
	public:
		ADD_OBJECT(SoundCue, Sound, 4)
		ADD_STRUCT(TrVGSCommandList__VGSCommandType, Command, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
