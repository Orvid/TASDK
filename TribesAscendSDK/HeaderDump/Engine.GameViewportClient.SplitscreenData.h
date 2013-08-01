#pragma once
#include "Engine.GameViewportClient.PerPlayerSplitscreenData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameViewportClient__SplitscreenData
	{
	public:
		ADD_STRUCT(ScriptArray<GameViewportClient__PerPlayerSplitscreenData>, PlayerData, 0)
	};
}
#undef ADD_STRUCT
