#pragma once
namespace UnrealScript
{
	struct AnimSequence__TimeModifier;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__TimeModifier
	{
	public:
		ADD_STRUCT(float, Time, 0)
		ADD_STRUCT(float, TargetStrength, 4)
	};
}
#undef ADD_STRUCT
