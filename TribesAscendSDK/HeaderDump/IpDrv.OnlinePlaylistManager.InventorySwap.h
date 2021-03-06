#pragma once
namespace UnrealScript
{
	struct OnlinePlaylistManager__InventorySwap;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlinePlaylistManager__InventorySwap
	{
	public:
		ADD_STRUCT(ScriptString*, SwapTo, 8)
		ADD_STRUCT(ScriptName, Original, 0)
	};
}
#undef ADD_STRUCT
