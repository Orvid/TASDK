#pragma once
namespace UnrealScript
{
	struct InternetLink__IpAddr;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InternetLink__IpAddr
	{
	public:
		ADD_STRUCT(int, Port, 4)
		ADD_STRUCT(int, Addr, 0)
	};
}
#undef ADD_STRUCT
