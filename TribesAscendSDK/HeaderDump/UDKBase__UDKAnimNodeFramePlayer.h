#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimNodeFramePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimNodeFramePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimNodeFramePlayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimNodeFramePlayer : public AnimNodeSequence
	{
	public:
			void SetAnimation( ScriptName Sequence, float RateScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKAnimNodeFramePlayer.SetAnimation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = Sequence;
				*( float* )( params + 8 ) = RateScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( float Perc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKAnimNodeFramePlayer.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Perc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
