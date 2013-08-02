#pragma once
namespace UnrealScript
{
	struct UDKMapMusicInfo__MusicForAMap;
}
#include "UDKBase.UDKMapMusicInfo.MusicSegment.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKMapMusicInfo__MusicForAMap
	{
	public:
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Victory, 84)
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Tension, 68)
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Suspense, 52)
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Intro, 36)
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Ambient, 20)
		ADD_STRUCT(UDKMapMusicInfo__MusicSegment, Action, 4)
		ADD_STRUCT(float, Tempo, 0)
	};
}
#undef ADD_STRUCT
