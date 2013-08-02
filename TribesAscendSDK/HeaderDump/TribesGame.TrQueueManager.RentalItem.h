#pragma once
namespace UnrealScript
{
	struct TrQueueManager__RentalItem;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrQueueManager__RentalItem
	{
	public:
		ADD_STRUCT(ScriptString*, RentalName, 12)
		ADD_STRUCT(int, Price, 0)
		ADD_STRUCT(int, LootId, 4)
		ADD_STRUCT(int, SortOrder, 8)
	};
}
#undef ADD_STRUCT
