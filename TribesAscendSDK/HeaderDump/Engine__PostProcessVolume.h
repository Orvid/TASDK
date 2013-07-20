#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PostProcessVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PostProcessVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PostProcessVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PostProcessVolume : public Volume
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_OBJECT( PostProcessVolume, NextLowerPriorityVolume )
			ADD_VAR( ::FloatProperty, Priority, 0xFFFFFFFF )
			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PostProcessVolume.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
