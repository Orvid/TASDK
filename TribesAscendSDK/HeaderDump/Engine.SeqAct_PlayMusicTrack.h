#pragma once
namespace UnrealScript
{
	class SeqAct_PlayMusicTrack;
}
#include "Engine.MusicTrackDataStructures.MusicTrackStruct.h"
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_PlayMusicTrack : public SequenceAction
	{
	public:
		ADD_STRUCT(MusicTrackDataStructures__MusicTrackStruct, MusicTrack, 232)
	};
}
#undef ADD_STRUCT
