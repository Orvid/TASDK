#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamGameMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamGameMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, AnnouncerSounds)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BlueDrawColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedDrawColor'!
		ADD_VAR(::StrProperty, YouAreOnBlueMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnRedMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequestTeamSwapPostfix, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequestTeamSwapPrefix, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
