#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKWeaponPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKWeaponPawn : public UDKVehicleBase
	{
	public:
			ADD_VAR( ::IntProperty, MySeatIndex, 0xFFFFFFFF )
			ADD_OBJECT( UDKWeapon, MyVehicleWeapon )
			ADD_OBJECT( UDKVehicle, MyVehicle )
			Vector GetTargetLocation( class Actor* RequestedBy, bool bRequestAlternateLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKWeaponPawn.GetTargetLocation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = RequestedBy;
				*( bool* )( params + 4 ) = bRequestAlternateLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
