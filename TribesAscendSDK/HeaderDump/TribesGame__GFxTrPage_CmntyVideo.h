#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_CmntyVideo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_CmntyVideo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_CmntyVideo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_CmntyVideo : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bValid, 0x1 )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowModel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.ShowModel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialAction( class GFxTrAction* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.SpecialAction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrAction** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillData( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.FillData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* FillOption( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.FillOption" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* FillDescription( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_CmntyVideo.FillDescription" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
