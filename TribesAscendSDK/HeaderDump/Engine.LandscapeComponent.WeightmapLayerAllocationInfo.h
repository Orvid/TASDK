#pragma once
namespace UnrealScript
{
	struct LandscapeComponent__WeightmapLayerAllocationInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct LandscapeComponent__WeightmapLayerAllocationInfo
	{
	public:
		ADD_STRUCT(byte, WeightmapTextureChannel, 9)
		ADD_STRUCT(byte, WeightmapTextureIndex, 8)
		ADD_STRUCT(ScriptName, LayerName, 0)
	};
}
#undef ADD_STRUCT
