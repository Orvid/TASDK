#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PostProcessChain." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PostProcessChain." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PostProcessChain." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PostProcessChain : public Object
	{
	public:
			class PostProcessEffect* FindPostProcessEffect( ScriptName EffectName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PostProcessChain.FindPostProcessEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = EffectName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PostProcessEffect** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
