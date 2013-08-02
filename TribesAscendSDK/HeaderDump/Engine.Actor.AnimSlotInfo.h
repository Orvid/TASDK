#pragma once
namespace UnrealScript
{
	struct Actor__AnimSlotInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Actor__AnimSlotInfo
	{
	public:
		ADD_STRUCT(ScriptName, SlotName, 0)
		ADD_STRUCT(ScriptArray<float>, ChannelWeights, 8)
	};
}
#undef ADD_STRUCT
