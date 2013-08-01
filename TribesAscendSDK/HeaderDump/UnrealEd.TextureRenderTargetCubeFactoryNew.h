#pragma once
#include "Core.Factory.h"
#include "UnrealEd.TextureRenderTargetCubeFactoryNew.Format.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTargetCubeFactoryNew : public Factory
	{
	public:
		ADD_STRUCT(int, Width, 112)
		ADD_STRUCT(TextureRenderTargetCubeFactoryNew__Format, Format, 116)
	};
}
#undef ADD_STRUCT
