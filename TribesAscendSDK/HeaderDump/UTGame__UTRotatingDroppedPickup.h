#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTRotatingDroppedPickup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTRotatingDroppedPickup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTRotatingDroppedPickup." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTRotatingDroppedPickup : public UTDroppedPickup
	{
	public:
			ADD_VAR( ::FloatProperty, YawRotationRate, 0xFFFFFFFF )
			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTRotatingDroppedPickup.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
