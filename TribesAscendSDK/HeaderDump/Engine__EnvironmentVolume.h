#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.EnvironmentVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.EnvironmentVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.EnvironmentVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class EnvironmentVolume : public Volume
	{
	public:
			ADD_VAR( ::BoolProperty, bSplitNavMesh, 0x1 )
			void SetSplitNavMesh( bool bNewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EnvironmentVolume.SetSplitNavMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
