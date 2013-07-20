#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ReachSpec." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ReachSpec." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ReachSpec." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ReachSpec : public Object
	{
	public:
			ADD_OBJECT( Actor, BlockedBy )
			ADD_VAR( ::BoolProperty, bDisabled, 0x10 )
			ADD_VAR( ::BoolProperty, bSkipPrune, 0x8 )
			ADD_VAR( ::BoolProperty, bCheckForObstructions, 0x4 )
			ADD_VAR( ::BoolProperty, bCanCutCorners, 0x2 )
			ADD_VAR( ::BoolProperty, bAddToNavigationOctree, 0x1 )
			ADD_VAR( ::ByteProperty, PathColorIndex, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bPruned, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLandingVelocity, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, reachFlags, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CollisionHeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CollisionRadius, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, Start )
			ADD_STRUCT( ::VectorProperty, Direction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Distance, 0xFFFFFFFF )
			int CostFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ReachSpec.CostFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class NavigationPoint* GetEnd(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ReachSpec.GetEnd" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			Vector GetDirection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ReachSpec.GetDirection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool IsBlockedFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ReachSpec.IsBlockedFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
