#pragma once
namespace UnrealScript
{
	struct TrMapMusicInfo__TrMapMusic;
}
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrMapMusicInfo__TrMapMusic
	{
	public:
		ADD_OBJECT(SoundCue, AmbientMusic, 28)
		ADD_OBJECT(SoundCue, TeamLost, 24)
		ADD_OBJECT(SoundCue, TeamWon, 20)
		ADD_OBJECT(SoundCue, DeathDirge, 16)
		ADD_OBJECT(SoundCue, FlagPossession, 12)
		ADD_OBJECT(SoundCue, BattleMusicHigh, 8)
		ADD_OBJECT(SoundCue, BattleMusicMed, 4)
		ADD_OBJECT(SoundCue, BattleMusicLow, 0)
	};
}
#undef ADD_OBJECT
