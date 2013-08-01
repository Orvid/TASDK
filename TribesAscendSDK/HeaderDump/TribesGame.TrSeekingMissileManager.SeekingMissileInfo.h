#pragma once
#include "TribesGame.TrProj_TrackingMissile.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrSeekingMissileManager__SeekingMissileInfo
	{
	public:
		ADD_OBJECT(TrProj_TrackingMissile, Missile, 0)
		ADD_OBJECT(TrPlayerController, VictimController, 4)
	};
}
#undef ADD_OBJECT
