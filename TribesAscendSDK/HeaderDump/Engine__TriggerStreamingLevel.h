#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TriggerStreamingLevel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TriggerStreamingLevel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TriggerStreamingLevel." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TriggerStreamingLevel : public Trigger
	{
	public:
			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TriggerStreamingLevel.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
