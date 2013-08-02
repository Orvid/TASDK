#pragma once
namespace UnrealScript
{
	struct UTCharInfo__CustomAIData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTCharInfo__CustomAIData
	{
	public:
		ADD_STRUCT(ScriptString*, FavoriteWeapon, 28)
		ADD_STRUCT(float, ReactionTime, 24)
		ADD_STRUCT(float, Jumpiness, 20)
		ADD_STRUCT(float, CombatStyle, 16)
		ADD_STRUCT(float, Aggressiveness, 12)
		ADD_STRUCT(float, Accuracy, 8)
		ADD_STRUCT(float, StrafingAbility, 4)
		ADD_STRUCT(float, Tactics, 0)
	};
}
#undef ADD_STRUCT
