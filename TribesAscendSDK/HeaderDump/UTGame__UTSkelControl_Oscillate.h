#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSkelControl_Oscillate." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSkelControl_Oscillate." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSkelControl_Oscillate." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSkelControl_Oscillate : public SkelControlSingleBone
	{
	public:
			ADD_VAR( ::BoolProperty, bReverseDirection, 0x1 )
			ADD_VAR( ::FloatProperty, CurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Period, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MaxDelta, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT