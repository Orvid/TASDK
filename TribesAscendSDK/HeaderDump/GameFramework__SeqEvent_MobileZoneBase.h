#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_MobileZoneBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_MobileZoneBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_MobileZoneBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileZoneBase : public SeqEvent_MobileBase
	{
	public:
			ADD_VAR( ::StrProperty, TargetZoneName, 0xFFFFFFFF )
			void AddToMobileInput( class MobilePlayerInput* MPI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqEvent_MobileZoneBase.AddToMobileInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobilePlayerInput** )params = MPI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
