#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.TitleFile.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineTitleFileDownloadMcp__TitleFileMcp : public OnlineSubsystem__TitleFile
	{
	public:
		ADD_STRUCT(Object__Pointer, HttpDownloader, 28)
	};
}
#undef ADD_STRUCT
