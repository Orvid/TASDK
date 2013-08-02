#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__NamedInterfaceDef;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__NamedInterfaceDef
	{
	public:
		ADD_STRUCT(ScriptName, InterfaceName, 0)
		ADD_STRUCT(ScriptString*, InterfaceClassName, 8)
	};
}
#undef ADD_STRUCT
