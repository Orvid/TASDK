#pragma once
#include "Engine.Settings.SettingsProperty.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__CommunityContentMetadata
	{
	public:
		ADD_STRUCT(int, ContentType, 0)
		ADD_STRUCT(ScriptArray<Settings__SettingsProperty>, MetadataItems, 4)
	};
}
#undef ADD_STRUCT
