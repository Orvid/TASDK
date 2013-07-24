#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFFlag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTCTFFlag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFFlag." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFFlag : public UTCarriedObject
	{
	public:
		ADD_VAR(::FloatProperty, LastLocationPingTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HoverboardingClothVelClamp, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RunningClothVelClamp, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bWasClothEnabled, 0x10)
		ADD_VAR(::BoolProperty, bRespawning, 0x8)
		ADD_VAR(::BoolProperty, bFadingOut, 0x4)
		ADD_VAR(::BoolProperty, bBringDownFromBright, 0x2)
		ADD_VAR(::BoolProperty, bBringUpBright, 0x1)
		ADD_OBJECT(ParticleSystem, RespawnEffect)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
