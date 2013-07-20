#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTMutator_SpeedFreak." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTMutator_SpeedFreak." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTMutator_SpeedFreak." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTMutator_SpeedFreak : public UTMutator
	{
	public:
			ADD_VAR( ::FloatProperty, GameSpeed, 0xFFFFFFFF )
			void InitMutator( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMutator_SpeedFreak.InitMutator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
