#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqCond_SwitchObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqCond_SwitchObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqCond_SwitchObject." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqCond_SwitchObject : public SeqCond_SwitchBase
	{
	public:
			void VerifyDefaultCaseValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqCond_SwitchObject.VerifyDefaultCaseValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsFallThruEnabled( int ValueIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqCond_SwitchObject.IsFallThruEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ValueIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InsertValueEntry( int InsertIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqCond_SwitchObject.InsertValueEntry" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = InsertIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveValueEntry( int RemoveIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqCond_SwitchObject.RemoveValueEntry" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = RemoveIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
