#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrJammerMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrJammerMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrJammerMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrJammerMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, JammedByEnemyJammerPack, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JammingViaOtherDropJammer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JammedByEnemyDropJammer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JammingForOther, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JammingViaOther, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT