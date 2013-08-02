#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__CommunityContentFile;
}
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__CommunityContentFile
	{
	public:
		ADD_STRUCT(int, ContentId, 0)
		ADD_STRUCT(int, FileId, 4)
		ADD_STRUCT(int, ContentType, 8)
		ADD_STRUCT(int, FileSize, 12)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, Owner, 16)
		ADD_STRUCT(int, DownloadCount, 24)
		ADD_STRUCT(float, AverageRating, 28)
		ADD_STRUCT(int, RatingCount, 32)
		ADD_STRUCT(int, LastRatingGiven, 36)
		ADD_STRUCT(ScriptString*, LocalFilePath, 40)
	};
}
#undef ADD_STRUCT
