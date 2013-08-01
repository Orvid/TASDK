#pragma once
#include "GameFramework.MobileMenuObject.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobileMenuImage.MenuImageDrawStyle.h"
#include "GameFramework.MobileMenuObject.UVCoords.h"
#include "Engine.Canvas.h"
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
	class MobileMenuImage : public MobileMenuObject
	{
	public:
		ADD_STRUCT(Object__LinearColor, ImageColor, 160)
		ADD_STRUCT(MobileMenuObject__UVCoords, ImageUVs, 140)
		ADD_STRUCT(MobileMenuImage__MenuImageDrawStyle, ImageDrawStyle, 136)
		ADD_OBJECT(Texture2D, Image, 132)
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32650);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
