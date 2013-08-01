#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameViewportClient__PerPlayerSplitscreenData
	{
	public:
		ADD_STRUCT(float, OriginY, 12)
		ADD_STRUCT(float, OriginX, 8)
		ADD_STRUCT(float, SizeY, 4)
		ADD_STRUCT(float, SizeX, 0)
	};
}
#undef ADD_STRUCT
