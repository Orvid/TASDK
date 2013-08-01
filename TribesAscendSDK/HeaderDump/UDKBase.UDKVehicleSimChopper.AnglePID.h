#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKVehicleSimChopper__AnglePID
	{
	public:
		ADD_STRUCT(float, PrevError, 16)
		ADD_STRUCT(float, PrevIntegral, 12)
		ADD_STRUCT(float, IGain, 8)
		ADD_STRUCT(float, DGain, 4)
		ADD_STRUCT(float, PGain, 0)
	};
}
#undef ADD_STRUCT
