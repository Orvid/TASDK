#pragma once
#include "Core.Factory.h"
#include "UnrealEd.TextureRenderTargetFactoryNew.Format.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTargetFactoryNew : public Factory
	{
	public:
		ADD_STRUCT(int, Width, 112)
		ADD_STRUCT(int, Height, 116)
		ADD_STRUCT(TextureRenderTargetFactoryNew__Format, Format, 120)
	};
}
#undef ADD_STRUCT
