#pragma once
namespace UnrealScript
{
	class UDKMapMusicInfo;
}
#include "Core.Object.h"
#include "UDKBase.UDKMapMusicInfo.ECrossfadeType.h"
#include "UDKBase.UDKMapMusicInfo.MusicForAMap.h"
#include "UDKBase.UDKMapMusicInfo.MusicSegment.h"
#include "UDKBase.UDKMapMusicInfo.StingersForAMap.h"
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
	class UDKMapMusicInfo : public Object
	{
	public:
		typedef UDKMapMusicInfo__ECrossfadeType ECrossfadeType;
		typedef UDKMapMusicInfo__MusicSegment MusicSegment;
		typedef UDKMapMusicInfo__StingersForAMap StingersForAMap;
		typedef UDKMapMusicInfo__MusicForAMap MusicForAMap;
		ADD_STRUCT(UDKMapMusicInfo__StingersForAMap, MapStingers, 160)
		ADD_STRUCT(UDKMapMusicInfo__MusicForAMap, MapMusic, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
