#pragma once
namespace UnrealScript
{
	struct GameplayEvents__DamageClassEventData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__DamageClassEventData
	{
	public:
		ADD_STRUCT(ScriptString*, DamageClassName, 0)
	};
}
#undef ADD_STRUCT
