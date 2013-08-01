#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrRibbonManager__RibbonData
	{
	public:
		ADD_STRUCT(int, Ribbon, 8)
		ADD_STRUCT(int, Type, 4)
		ADD_STRUCT(int, Id, 0)
	};
}
#undef ADD_STRUCT
