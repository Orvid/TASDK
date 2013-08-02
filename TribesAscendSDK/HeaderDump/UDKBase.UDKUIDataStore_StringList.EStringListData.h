#pragma once
namespace UnrealScript
{
	struct UDKUIDataStore_StringList__EStringListData;
}
#include "UDKBase.UDKUIDataProvider_StringArray.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct UDKUIDataStore_StringList__EStringListData
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Strings, 36)
		ADD_OBJECT(UDKUIDataProvider_StringArray, DataProvider, 48)
		ADD_STRUCT(int, DefaultValueIndex, 32)
		ADD_STRUCT(ScriptString*, CurrentValue, 20)
		ADD_STRUCT(ScriptString*, ColumnHeaderText, 8)
		ADD_STRUCT(ScriptName, Tag, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
