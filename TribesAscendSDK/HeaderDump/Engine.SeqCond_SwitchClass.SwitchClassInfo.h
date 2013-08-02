#pragma once
namespace UnrealScript
{
	struct SeqCond_SwitchClass__SwitchClassInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SeqCond_SwitchClass__SwitchClassInfo
	{
	public:
		ADD_STRUCT(byte, bFallThru, 8)
		ADD_STRUCT(ScriptName, ClassName, 0)
	};
}
#undef ADD_STRUCT
