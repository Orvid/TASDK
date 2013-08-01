#pragma once
#include "Engine.Font.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.Color.h"
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
	struct HUD__KismetDrawTextInfo
	{
	public:
		ADD_STRUCT(Object__Vector2D, MessageOffset, 36)
		ADD_STRUCT(float, MessageEndTime, 48)
		ADD_STRUCT(Object__Color, MessageColor, 44)
		ADD_STRUCT(Object__Vector2D, MessageFontScale, 28)
		ADD_OBJECT(Font, MessageFont, 24)
		ADD_STRUCT(ScriptString*, AppendedText, 12)
		ADD_STRUCT(ScriptString*, MessageText, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
