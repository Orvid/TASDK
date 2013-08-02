#pragma once
namespace UnrealScript
{
	struct TrAnimNodeTurnInPlace__RotTransitionInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrAnimNodeTurnInPlace__RotTransitionInfo
	{
	public:
		ADD_STRUCT(ScriptName, TransName, 4)
		ADD_STRUCT(float, RotationOffset, 0)
	};
}
#undef ADD_STRUCT
