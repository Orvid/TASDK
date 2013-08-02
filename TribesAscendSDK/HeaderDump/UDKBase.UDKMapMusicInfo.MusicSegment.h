#pragma once
namespace UnrealScript
{
	struct UDKMapMusicInfo__MusicSegment;
}
#include "Engine.SoundCue.h"
#include "UDKBase.UDKMapMusicInfo.ECrossfadeType.h"
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
	struct UDKMapMusicInfo__MusicSegment
	{
	public:
		ADD_OBJECT(SoundCue, TheCue, 12)
		ADD_STRUCT(int, CrossfadeToMeNumMeasuresDuration, 8)
		ADD_STRUCT(UDKMapMusicInfo__ECrossfadeType, CrossfadeRule, 4)
		ADD_STRUCT(float, TempoOverride, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
