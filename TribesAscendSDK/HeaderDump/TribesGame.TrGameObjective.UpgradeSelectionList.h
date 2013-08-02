#pragma once
namespace UnrealScript
{
	struct TrGameObjective__UpgradeSelectionList;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrGameObjective__UpgradeSelectionList
	{
	public:
		ADD_STRUCT(ScriptName, PropertyName, 16)
		ADD_STRUCT(float, NewValue, 12)
		ADD_STRUCT(int, UpgradeCreditCost, 8)
		ADD_STRUCT(int, UpgradeLevel, 4)
		ADD_OBJECT(ScriptClass, UpgradeClass, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
