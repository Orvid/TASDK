#pragma once
namespace UnrealScript
{
	struct GFxTrPage_Vehicle__VehicleOption;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxTrPage_Vehicle__VehicleOption
	{
	public:
		ADD_STRUCT(ScriptString*, DisplayName, 28)
		ADD_STRUCT(ScriptString*, ClassName, 16)
		ADD_STRUCT(int, MaxCount, 12)
		ADD_STRUCT(int, Count, 8)
		ADD_STRUCT(int, Icon, 4)
		ADD_STRUCT(int, Cost, 0)
	};
}
#undef ADD_STRUCT
