#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ScriptedTexture." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ScriptedTexture." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ScriptedTexture." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ScriptedTexture : public TextureRenderTarget2D
	{
	public:
			void Render( class Canvas* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ScriptedTexture.Render" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bSkipNextClear, 0x2 )
			ADD_VAR( ::BoolProperty, bNeedsUpdate, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
