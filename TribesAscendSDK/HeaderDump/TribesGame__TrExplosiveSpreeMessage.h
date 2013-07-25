#pragma once
#include "UTGame__UTLocalMessage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrExplosiveSpreeMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrExplosiveSpreeMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrExplosiveSpreeMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, EndSpreeNoteTrailer, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, SpreeSound)
		ADD_VAR(::StrProperty, SelfSpreeNote, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpreeNote, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MultiKillString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndSelfSpree, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndSpreeNote, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
