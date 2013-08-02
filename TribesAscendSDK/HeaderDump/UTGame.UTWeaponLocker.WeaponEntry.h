#pragma once
namespace UnrealScript
{
	struct UTWeaponLocker__WeaponEntry;
}
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct UTWeaponLocker__WeaponEntry
	{
	public:
		ADD_OBJECT(ScriptClass, WeaponClass, 0)
	};
}
#undef ADD_OBJECT
