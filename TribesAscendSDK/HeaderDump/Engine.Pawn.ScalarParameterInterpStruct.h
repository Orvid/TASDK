#pragma once
namespace UnrealScript
{
	struct Pawn__ScalarParameterInterpStruct;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Pawn__ScalarParameterInterpStruct
	{
	public:
		ADD_STRUCT(float, WarmupTime, 16)
		ADD_STRUCT(float, InterpTime, 12)
		ADD_STRUCT(float, ParameterValue, 8)
		ADD_STRUCT(ScriptName, ParameterName, 0)
	};
}
#undef ADD_STRUCT
