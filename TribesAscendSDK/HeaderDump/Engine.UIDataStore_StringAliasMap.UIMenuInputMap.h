#pragma once
namespace UnrealScript
{
	struct UIDataStore_StringAliasMap__UIMenuInputMap;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataStore_StringAliasMap__UIMenuInputMap
	{
	public:
		ADD_STRUCT(ScriptString*, MappedText, 16)
		ADD_STRUCT(ScriptName, Set, 8)
		ADD_STRUCT(ScriptName, FieldName, 0)
	};
}
#undef ADD_STRUCT
