#pragma once
#include "Core.Object.QWord.h"
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct WorldInfo__ScreenMessageString
	{
	public:
		ADD_STRUCT(QWord, Key, 0)
		ADD_STRUCT(ScriptString*, ScreenMessage, 8)
		ADD_STRUCT(Object__Color, DisplayColor, 20)
		ADD_STRUCT(float, TimeToDisplay, 24)
		ADD_STRUCT(float, CurrentTimeDisplayed, 28)
	};
}
#undef ADD_STRUCT
