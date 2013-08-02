#pragma once
namespace UnrealScript
{
	struct PostProcessVolume__LUTBlender;
}
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PostProcessVolume__LUTBlender
	{
	public:
		ADD_STRUCT(ScriptArray<class Texture*>, LUTTextures, 0)
		ADD_STRUCT(ScriptArray<float>, LUTWeights, 12)
	};
}
#undef ADD_STRUCT
