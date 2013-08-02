#pragma once
namespace UnrealScript
{
	struct DMC_Prototype__DMCNewVar;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct DMC_Prototype__DMCNewVar
	{
	public:
		ADD_STRUCT(ScriptName, VarType, 8)
		ADD_STRUCT(ScriptName, VarName, 0)
	};
}
#undef ADD_STRUCT
