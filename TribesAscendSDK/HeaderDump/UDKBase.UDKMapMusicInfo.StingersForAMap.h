#pragma once
namespace UnrealScript
{
	struct UDKMapMusicInfo__StingersForAMap;
}
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct UDKMapMusicInfo__StingersForAMap
	{
	public:
		ADD_OBJECT(SoundCue, ScoreWinning, 56)
		ADD_OBJECT(SoundCue, ScoreTie, 52)
		ADD_OBJECT(SoundCue, ScoreLosing, 48)
		ADD_OBJECT(SoundCue, ReturnFlag, 44)
		ADD_OBJECT(SoundCue, MultiKill, 40)
		ADD_OBJECT(SoundCue, MonsterKill, 36)
		ADD_OBJECT(SoundCue, MajorKill, 32)
		ADD_OBJECT(SoundCue, LongKillingSpree, 28)
		ADD_OBJECT(SoundCue, Kill, 24)
		ADD_OBJECT(SoundCue, GrabFlag, 20)
		ADD_OBJECT(SoundCue, FlagReturned, 16)
		ADD_OBJECT(SoundCue, FirstKillingSpree, 12)
		ADD_OBJECT(SoundCue, EnemyGrabFlag, 8)
		ADD_OBJECT(SoundCue, DoubleKill, 4)
		ADD_OBJECT(SoundCue, Died, 0)
	};
}
#undef ADD_OBJECT
