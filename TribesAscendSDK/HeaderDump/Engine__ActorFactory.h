#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactory : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bShowInEditorQuickMenu, 0x2 )
			ADD_VAR( ::BoolProperty, bPlaceable, 0x1 )
			ADD_OBJECT( ScriptClass, NewActorClass )
			ADD_VAR( ::IntProperty, AlternateMenuPriority, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MenuPriority, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MenuName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, GameplayActorClass )
			void PostCreateActor( class Actor* NewActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ActorFactory.PostCreateActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = NewActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
