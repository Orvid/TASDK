#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrMultiKillMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrMultiKillMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrMultiKillMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrMultiKillMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundNodeWave, KillSound )
			ADD_VAR( ::StrProperty, KillString, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.GetString" );
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

			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.ClientReceive" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.AnnouncementSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = MessageIndex;
				*( class Object** )( params + 4 ) = OptionalObject;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundNodeWave** )( params + function->return_val_offset() );
			}

			int GetFontSize( int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.GetFontSize" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Switch;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI1;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI2;
				*( class PlayerReplicationInfo** )( params + 12 ) = LocalPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool ShouldBeRemoved( class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.ShouldBeRemoved" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTQueuedAnnouncement** )params = MyAnnouncement;
				*( ScriptClass** )( params + 4 ) = NewAnnouncementClass;
				*( int* )( params + 8 ) = NewMessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AddAnnouncement( class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMultiKillMessage.AddAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTAnnouncer** )params = Announcer;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
