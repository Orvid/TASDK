#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AudioDevice__AudioClassInfo
	{
	public:
		ADD_STRUCT(int, SizeRealTime, 12)
		ADD_STRUCT(int, NumRealTime, 8)
		ADD_STRUCT(int, SizeResident, 4)
		ADD_STRUCT(int, NumResident, 0)
	};
}
#undef ADD_STRUCT
