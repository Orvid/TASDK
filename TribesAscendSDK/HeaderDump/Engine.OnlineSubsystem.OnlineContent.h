#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineContent;
}
#include "Engine.OnlineSubsystem.EOnlineContentType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineContent
	{
	public:
		ADD_STRUCT(OnlineSubsystem__EOnlineContentType, ContentType, 0)
		ADD_STRUCT(byte, UserIndex, 1)
		ADD_STRUCT(int, DeviceID, 4)
		ADD_STRUCT(ScriptString*, FriendlyName, 8)
		ADD_STRUCT(ScriptString*, Filename, 20)
		ADD_STRUCT(ScriptString*, ContentPath, 32)
		ADD_STRUCT(ScriptArray<ScriptString*>, ContentPackages, 44)
		ADD_STRUCT(ScriptArray<ScriptString*>, ContentFiles, 56)
	};
}
#undef ADD_STRUCT
