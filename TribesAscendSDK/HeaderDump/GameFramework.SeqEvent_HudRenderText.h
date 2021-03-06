#pragma once
namespace UnrealScript
{
	class SeqEvent_HudRenderText;
}
#include "Core.Object.Color.h"
#include "Engine.Canvas.h"
#include "Engine.Font.h"
#include "Engine.HUD.h"
#include "GameFramework.SeqEvent_HudRender.h"
#include "GameFramework.SeqEvent_HudRenderText.ETextDrawMethod.h"
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
	class SeqEvent_HudRenderText : public SeqEvent_HudRender
	{
	public:
		typedef SeqEvent_HudRenderText__ETextDrawMethod ETextDrawMethod;
		ADD_STRUCT(SeqEvent_HudRenderText__ETextDrawMethod, TextDrawMethod, 308)
		ADD_STRUCT(ScriptString*, DisplayText, 296)
		ADD_STRUCT(Vector, DisplayLocation, 284)
		ADD_STRUCT(Object__Color, DisplayColor, 280)
		ADD_OBJECT(Font, DisplayFont, 276)
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33005);
			byte params[8] = { NULL };
			*(class Canvas**)params = TargetCanvas;
			*(class HUD**)&params[4] = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33017);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
