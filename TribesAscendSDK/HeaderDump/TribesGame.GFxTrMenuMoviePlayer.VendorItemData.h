#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxTrMenuMoviePlayer__VendorItemData
	{
	public:
		ADD_STRUCT(ScriptString*, Description, 20)
		ADD_STRUCT(ScriptString*, Title, 8)
		ADD_STRUCT(int, LootId, 4)
		ADD_STRUCT(int, Price, 0)
	};
}
#undef ADD_STRUCT
