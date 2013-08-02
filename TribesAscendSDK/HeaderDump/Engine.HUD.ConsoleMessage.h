#pragma once
namespace UnrealScript
{
	struct HUD__ConsoleMessage;
}
#include "Core.Object.Color.h"
#include "Engine.PlayerReplicationInfo.h"
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
	struct HUD__ConsoleMessage
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, PRI, 20)
		ADD_STRUCT(float, MessageLife, 16)
		ADD_STRUCT(Object__Color, TextColor, 12)
		ADD_STRUCT(ScriptString*, Text, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
