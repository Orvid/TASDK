#pragma once
namespace UnrealScript
{
	struct UDKVehicle__DamageParamScales;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKVehicle__DamageParamScales
	{
	public:
		ADD_STRUCT(float, Scale, 8)
		ADD_STRUCT(ScriptName, DamageParamName, 0)
	};
}
#undef ADD_STRUCT
