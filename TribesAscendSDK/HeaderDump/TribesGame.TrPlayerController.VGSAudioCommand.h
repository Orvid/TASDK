#pragma once
namespace UnrealScript
{
	struct TrPlayerController__VGSAudioCommand;
}
#include "Engine.SoundCue.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrPlayerController__VGSAudioCommand
	{
	public:
		ADD_OBJECT(SoundCue, QueuedSoundCue, 8)
		ADD_OBJECT(TrPlayerReplicationInfo, VGSInstigator, 0)
	};
}
#undef ADD_OBJECT
