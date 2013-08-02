#pragma once
namespace UnrealScript
{
	struct OnlineGameSearch__NamedObjectProperty;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameSearch__NamedObjectProperty
	{
	public:
		ADD_STRUCT(ScriptName, ObjectPropertyName, 0)
		ADD_STRUCT(ScriptString*, ObjectPropertyValue, 8)
	};
}
#undef ADD_STRUCT
