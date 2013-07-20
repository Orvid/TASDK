#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCTFScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCTFScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCTFScoreMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCTFScoreMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, TeamHigherScore, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerHattrick, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1JustGotAhead, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0JustGotAhead, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1LeadingBy2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0LeadingBy2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1Scored, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0Scored, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreNone, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreNone, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreRed, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, TeamScoreSounds )
			byte AnnouncementLevel( byte MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCTFScoreMessage.AnnouncementLevel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCTFScoreMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )params = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundNodeWave* AnnouncementSound( int MessageIndex, class Object* OptionalObject, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCTFScoreMessage.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCTFScoreMessage.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Switch;
				*( bool* )( params + 4 ) = bPRI1HUD;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetColor( int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCTFScoreMessage.GetColor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Switch;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI_;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
