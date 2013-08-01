#pragma once
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Texture2D__TextureLinkedListMirror
	{
	public:
		ADD_STRUCT(Object__Pointer, PrevLink, 8)
		ADD_STRUCT(Object__Pointer, Next, 4)
		ADD_STRUCT(Object__Pointer, Element, 0)
	};
}
#undef ADD_STRUCT
