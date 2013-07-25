#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Engine__SoundNodeWave.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCTFScoreMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCTFScoreMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCTFScoreMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, TeamHigherScore, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerHattrick, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team1JustGotAhead, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team0JustGotAhead, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team1LeadingBy2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team0LeadingBy2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team1Scored, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Team0Scored, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScoreNone, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PreScoreNone, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScoreBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PreScoreBlue, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScoreRed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PreScoreRed, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, TeamScoreSounds)
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'GetColor'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
