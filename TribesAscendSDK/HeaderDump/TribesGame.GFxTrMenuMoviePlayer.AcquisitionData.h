#pragma once
namespace UnrealScript
{
	struct GFxTrMenuMoviePlayer__AcquisitionData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxTrMenuMoviePlayer__AcquisitionData
	{
	public:
		ADD_STRUCT(int, Icon, 36)
		ADD_STRUCT(ScriptString*, Type, 24)
		ADD_STRUCT(ScriptString*, Text, 12)
		ADD_STRUCT(ScriptString*, Title, 0)
	};
}
#undef ADD_STRUCT
