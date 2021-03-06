#pragma once
namespace UnrealScript
{
	struct OnlineGameSearch__OnlineGameSearchResult;
}
#include "Core.Object.Pointer.h"
#include "Engine.OnlineGameSettings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct OnlineGameSearch__OnlineGameSearchResult
	{
	public:
		ADD_OBJECT(OnlineGameSettings, GameSettings, 0)
		ADD_STRUCT(Object__Pointer, PlatformData, 4)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
