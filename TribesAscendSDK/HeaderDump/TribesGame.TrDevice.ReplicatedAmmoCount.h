#pragma once
namespace UnrealScript
{
	struct TrDevice__ReplicatedAmmoCount;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrDevice__ReplicatedAmmoCount
	{
	public:
		ADD_STRUCT(int, ClipAmmoCount, 4)
		ADD_STRUCT(int, CarriedAmmoCount, 0)
	};
}
#undef ADD_STRUCT
