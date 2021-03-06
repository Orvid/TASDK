#pragma once
namespace UnrealScript
{
	struct GameplayEvents__ProjectileClassEventData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__ProjectileClassEventData
	{
	public:
		ADD_STRUCT(ScriptString*, ProjectileClassName, 0)
	};
}
#undef ADD_STRUCT
