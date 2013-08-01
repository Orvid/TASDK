#pragma once
#include "Engine.Texture2D.h"
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
	struct Texture2DComposite__SourceTexture2DRegion
	{
	public:
		ADD_OBJECT(Texture2D, Texture2D, 16)
		ADD_STRUCT(int, SizeY, 12)
		ADD_STRUCT(int, SizeX, 8)
		ADD_STRUCT(int, OffsetY, 4)
		ADD_STRUCT(int, OffsetX, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
