#pragma once
#include "Engine.Settings.EOnlineDataAdvertisementType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Settings__LocalizedStringSetting
	{
	public:
		ADD_STRUCT(int, Id, 0)
		ADD_STRUCT(int, ValueIndex, 4)
		ADD_STRUCT(Settings__EOnlineDataAdvertisementType, AdvertisementType, 8)
	};
}
#undef ADD_STRUCT
