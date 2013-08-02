#pragma once
namespace UnrealScript
{
	struct GameViewportClient__TitleSafeZoneArea;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameViewportClient__TitleSafeZoneArea
	{
	public:
		ADD_STRUCT(float, MaxPercentX, 0)
		ADD_STRUCT(float, RecommendedPercentX, 8)
		ADD_STRUCT(float, MaxPercentY, 4)
		ADD_STRUCT(float, RecommendedPercentY, 12)
	};
}
#undef ADD_STRUCT
