#pragma once
namespace UnrealScript
{
	struct UDKAnimNodeSequenceByBoneRotation__AnimByRotation;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKAnimNodeSequenceByBoneRotation__AnimByRotation
	{
	public:
		ADD_STRUCT(ScriptName, AnimName, 12)
		ADD_STRUCT(Rotator, DesiredRotation, 0)
	};
}
#undef ADD_STRUCT
