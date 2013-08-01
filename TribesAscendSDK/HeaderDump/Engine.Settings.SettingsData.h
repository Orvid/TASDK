#pragma once
#include "Engine.Settings.ESettingsDataType.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Settings__SettingsData
	{
	public:
		ADD_STRUCT(Settings__ESettingsDataType, Type, 0)
		ADD_STRUCT(int, Value1, 4)
		ADD_STRUCT(Object__Pointer, Value2, 8)
	};
}
#undef ADD_STRUCT
