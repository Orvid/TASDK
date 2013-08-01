#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKUIDataStore_StringAliasBindingMap__ControllerMap
	{
	public:
		ADD_STRUCT(ScriptString*, PS3Mapping, 20)
		ADD_STRUCT(ScriptString*, XBoxMapping, 8)
		ADD_STRUCT(ScriptName, KeyName, 0)
	};
}
#undef ADD_STRUCT
