#pragma once
namespace UnrealScript
{
	struct TrMapMusicInfo__TrMapStingers;
}
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrMapMusicInfo__TrMapStingers
	{
	public:
		ADD_OBJECT(SoundCue, TeamRabbitFriendlyPickedUpFlag, 52)
		ADD_OBJECT(SoundCue, TeamRabbitEnemyPickedUpFlag, 48)
		ADD_OBJECT(SoundCue, EnemyFlagDropped, 44)
		ADD_OBJECT(SoundCue, EnemyFlagReturned, 40)
		ADD_OBJECT(SoundCue, EnemyFlagCaptured, 36)
		ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromDropped, 32)
		ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromBase, 28)
		ADD_OBJECT(SoundCue, FriendlyFlagDropped, 24)
		ADD_OBJECT(SoundCue, FriendlyFlagReturned, 20)
		ADD_OBJECT(SoundCue, FriendlyFlagCaptured, 16)
		ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromDropped, 12)
		ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromBase, 8)
		ADD_OBJECT(SoundCue, PlayerLost, 4)
		ADD_OBJECT(SoundCue, PlayerWon, 0)
	};
}
#undef ADD_OBJECT
