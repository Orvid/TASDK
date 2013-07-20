#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDataStore_GameSearchHistory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDataStore_GameSearchHistory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDataStore_GameSearchHistory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDataStore_GameSearchHistory : public UTDataStore_GameSearchPersonal
	{
	public:
			bool HasOutstandingQueries( bool bRestrictCheckToSelf )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchHistory.HasOutstandingQueries" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bRestrictCheckToSelf;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTDataStore_GameSearchFavorites, FavoritesGameSearchDataStore )
			ADD_OBJECT( ScriptClass, FavoritesGameSearchDataStoreClass )
			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchHistory.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
