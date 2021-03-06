#pragma once
namespace UnrealScript
{
	class TrMapMusicInfo;
}
#include "TribesGame.TrMapMusicInfo.TrMapMusic.h"
#include "TribesGame.TrMapMusicInfo.TrMapStingers.h"
#include "UDKBase.UDKMapMusicInfo.h"
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
	class TrMapMusicInfo : public UDKMapMusicInfo
	{
	public:
		typedef TrMapMusicInfo__TrMapStingers TrMapStingers;
		typedef TrMapMusicInfo__TrMapMusic TrMapMusic;
		ADD_STRUCT(TrMapMusicInfo__TrMapStingers, m_MapStingers, 252)
		ADD_STRUCT(TrMapMusicInfo__TrMapMusic, m_MapMusic, 220)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
