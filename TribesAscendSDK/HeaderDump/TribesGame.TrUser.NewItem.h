#pragma once
namespace UnrealScript
{
	struct TrUser__NewItem;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrUser__NewItem
	{
	public:
		ADD_STRUCT(int, ItemId, 8)
		ADD_STRUCT(int, Type, 4)
		ADD_STRUCT(int, ClassId, 0)
	};
}
#undef ADD_STRUCT
