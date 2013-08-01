#pragma once
#include "Engine.MaterialExpressionTextureSampleParameter2D.h"
#include "Engine.MaterialExpressionAntialiasedTextureMask.ETextureColorChannel.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionAntialiasedTextureMask : public MaterialExpressionTextureSampleParameter2D
	{
	public:
		ADD_STRUCT(MaterialExpressionAntialiasedTextureMask__ETextureColorChannel, Channel, 168)
		ADD_STRUCT(float, Threshold, 164)
	};
}
#undef ADD_STRUCT
