#pragma once
namespace UnrealScript
{
	struct SeqAct_Interp__CameraCutInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SeqAct_Interp__CameraCutInfo
	{
	public:
		ADD_STRUCT(float, TimeStamp, 12)
		ADD_STRUCT(Vector, Location, 0)
	};
}
#undef ADD_STRUCT
