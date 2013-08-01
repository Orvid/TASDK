#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTDataStore_GameSearchDM__PersistentLocalizedSettingValue
	{
	public:
		ADD_STRUCT(int, ValueId, 4)
		ADD_STRUCT(int, SettingId, 0)
	};
}
#undef ADD_STRUCT
